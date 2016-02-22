#!/usr/bin/env python
# coding: utf-8


# python script that takes a list of input files in command line and generates a
# list of their trigrams.


# returns a list of the trigrams of a word
# if word has less than 3 letters, returns an empty list 
def trigrams(word) :
	L = []
	length = len(word)
	start = 0
	for end in range(3, length + 1) :
		L+= [word[start : end]]
		start += 1
	return L


# USED AS A STUB for further more complicated ways of storage
# receives a storage object, a word and a list of trigrams associated with it
def setWordTrigram(storage, word, trigramsList) :
	storage[word] = trigramsList

# USED AS A STUB for further more complicated ways of storage
# receives a storage object, a word and returns the trigram associated with it
def getWordTrigram(storage, word) :
	return storage[word]


# receives a list of files and indexes each one's letters trigrams in the storage given
def indexText(files, filesNumber, storage) :
	for i in range(filesNumber) :
		f = open(files[i], "r")
		txt = f.read()
		words = txt.split()
		for j in range(len(words)) : 
			words[j] = " " + words[j] + " "		# include blanks before and after
			setWordTrigram(storage, words[j], trigrams(words[j]))
		f.close()


# counts how many trigrams of tri1 are in tri2 
def inCommon(tri1, tri2) :
	cpt = 0
	for trigram in tri1 :
		if trigram in tri2 :
			cpt += 1
		else :
			cpt -= 1
	return cpt

	
# find the closest word to given word in given storage object
def findClosestWord(word, storage) :
	trigram = trigrams(word)
	best = 0
	for word in dic :
		curr = inCommon(trigram, getWordTrigram(storage, word))
		if curr > best :
			best = curr
			closest = word
	return word

################################### main ######################################

from pprint import pprint
from sys import argv

dic = {}
listOfBooks = []
for book in argv[1:] : listOfBooks += [book]

indexText(listOfBooks, len(argv) - 1, dic)
print "we made a dictionary of ", len(dic), " entries "

findClosestWord(" you ", dic)
