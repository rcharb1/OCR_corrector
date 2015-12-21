#include <stdio.h>
#include <stdlib.h>

int min_ter(int a, int b, int c)
{
	tmp = (a > b) ?a : b;
	return (c > tmp) : c : tmp;
}


int min_edit_dist(char* str1, char* str2, int m, int n)
{
    /* Create a table to store results of subproblems */
    int matrix[m+1][n+1];
 	int i = 0, j = 0;
 	
    /* Fill it in bottom up way */
    for (i = 0; i <= m; ++i)
    {
        for (j = 0; j <= n; ++j)
        {
            /* If first string is empty, insert all characters of second string */
            if (i == 0)
            {
                matrix[i][j] = j;  /* min operations = j */
 			}
            /* If second string is empty, remove all characters of second string */
            else if (j == 0)
            {
                matrix[i][j] = i; /* Min. operations = i */
 			}
            /* If last characters are same, ignore last char and recur for remaining string */
            else if (str1[i-1] == str2[j-1])
            {
                matrix[i][j] = matrix[i-1][j-1];
 			}
            /* If last character are different, consider all possibilities and find minimum */
            else
            {
                matrix[i][j] = 1 + min_ter(matrix[i][j-1],	/* Insert */
                                   matrix[i-1][j],			/* Remove */
                                   matrix[i-1][j-1]);		/* Replace */
        	}
        }
    }
    return matrix[m][n];
}
/* Python solution

def minEditDist(str1, str2, m,n) :
    # Create a table to store results of subproblems 
    for x in range(n+1) :
    	for y in range(m+1) :
    		matrix[x][y] = 0
 	# Fill it in bottom up way 
    for i in range(m + 1):
        for j in range(n + 1) :
            # If first string is empty, insert all characters of second string 
            if i == 0 :
                matrix[i][j] = j  # min operations = j 
            # If second string is empty, remove all characters of second string 
            elif j == 0 :
                matrix[i][j] = i # Min. operations = i 
            # If last characters are same, ignore last char and recur for remaining string 
            elif str1[i-1] == str2[j-1] :
                matrix[i][j] = matrix[i-1][j-1]
            # If last character are different, consider all possibilities and find minimum 
            else :
                matrix[i][j] = 1 + min(matrix[i][j-1],	# Insert 
                                   matrix[i-1][j],			# Remove 
                                   matrix[i-1][j-1]);		# Replace
    return matrix[m][n]

*/


def trigrams(word) :
	L = []
	length = len(word)
	start = 0
	for end in range(3, length + 1) :
		L+= [word[start : end]]
		start += 1
	return L


from pprint import pprint

# index all words of a certain file according to its trigrams
def indexText(file) :
	dic = {}
	f = open(file, "r")
	txt = f.read()
	words = txt.split()
	for i in range(len(words)) : 
		words[i] = " " + words[i] + " "
		dic[words[i]] = trigrams(words[i])
	f.close()
	return dic

# counts how many trigrams of tri1 are in tri2 
def inCommon(tri1, tri2) :
	cpt = 0
	for trigram in tri1 :
		if trigram in tri2 :
			print tri1, tri2
			cpt += 1
		else :
			cpt -= 1
	print cpt
	return cpt


	
# find the closest word to given word in given dictionary
def findClosestWord(word, dic) :
	trigram = trigrams(word)
	best = 0
	for word in dic :
		curr = inCommon(trigram, dic[word])
		if curr > best :
			best = curr
			closest = word
	return word



dic = indexText("random_book")
findClosestWord(" you ", dic)



