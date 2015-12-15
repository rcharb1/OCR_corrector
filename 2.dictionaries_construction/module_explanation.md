#Explanation of module dictionaries_construction

##General purpose
This module creates one or several dictionary structures in one or several langages.

##Needed files
I think we have 2 solutions :
* Either to take one or a few dictionary files in the format one entry per line and to index the terms in the appropriate structure. It is probably important to have a few dictionaries in each language to be able to cover as many words as possible.
* To dynamically create such a dictionary from a huge corpus of texts
The first method probably makes more sense...
##Output files
It might be useful to use a database (as Cyril suggested) since we are talking about a big quantity of data that is not very organized.
**Note** this module is also a preparation module that does not need to be done at every call of the OCR corrector.
Our program should probably test if the database had been filled and decide wether he has to run this module or not.
The fact that we use a database could allow us to validate the database course as well, but we have to make sure that each one of us "does something" in this field
(I don't know about you but I don't know anything about databases yet, I have to learn)

##Used tools
It would probably be Python and NoSQL as Cyril suggested.

##Questions arisen to discuss
* Does our program support several languages?
* If it is the case, what will be the naming conventions of the dictionary files ex: english1.txt english2.txt francais1.txt etc.

## each one and everybody's comments
Please feel free to add your reflexions.
