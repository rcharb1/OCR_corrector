#Explanation of module OCR_common_errors

##General purpose
This module dynamically creates an organized compilation of all common errors of a specific OCR.
Each one of them is associated with its relative frequence. (per 1000 characters for example)


##Needed files
We need to have at least 2 files : one is an original text file while the second is the result of these 2 successive conversions :
* Conversion from txt to pdf.
* Conversion from pdf to txt through the OCR program.
We can have as many pairs of 2 as we want, for example if we want to support different types of OCR where each one is characterized by its own mistakes.

##Output files
We need to create one or several xml files to contain the association of errors -> real original word.
We can have an organization looking like something like that :
error1 -> {first interpretation : percent}, {second interpretation : percent} etc.
error2 -> {first interpretation : percent} 
etc...

If several OCR are given, we need to create an xml file for each one of them.

##Used tools (to be discussed)
Python might be a good solution, coupled with xml.
Does anybody master interaction between a program and the xml ?
I mean : how do you make a program (python for example) to write xml code ?

##Questions arisen to discuss (please edit and add)
* Do we choose to support a few OCR programs ?
* How do we handle the case of a terribly deficient OCR ? We have to decide of a limit of consistency and define the program's behavior in a extreme case.
## each one and everybody's comments
