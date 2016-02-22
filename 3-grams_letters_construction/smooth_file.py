#!/usr/bin/env python
# coding: utf-8

# python script that takes a list of input files in command line and generates a
# another list of files smoothing it according to the configuration.

############## edit to configure the stringency of the smoothing ###############
removePunctuation = True
lowerCapitals = True
stopNumbers = True
prefix = "smoothed_"	# prefix of the generated files
stopList = "\",.;:><?/*'-_)(&^%$##@!`~|\\[]{}+="

def stop(letter) :
	stop = (removePunctuation and letter in stopList) or (letter.isdigit() and stopNumbers)
	if lowerCapitals : letter = letter.lower()
	if stop : return " "
	return letter

def smooth(fileName) :
	smoothedFileName = prefix + fileName
	input = open(fileName, "r")
	smoothed = open(smoothedFileName, "w")
	text = input.read()
	input.close()
	for letter in text :
		smoothed.write(stop(letter))
	smoothed.close()

#################################### main ######################################

from sys import argv

for book in argv[1:] :
	smooth(book)


