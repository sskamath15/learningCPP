# learningCPP
Repo tracks some mini-projects as I learn C++

# count3Mer.cpp
This file takes a single string as input and outputs a histogram of all 3-mers. The alphabet is {A, C, G, T}. The code only counts the 3-mers on the input string and does not consider base pair complements.
The test input for this file was chm13.v1.1.fasta found at https://s3-us-west-2.amazonaws.com/human-pangenomics/T2T/CHM13/assemblies/chm13.draft_v1.1.fasta.gz

The input file was parsed before being used as input. Different chromosome sequences were stored in different files and all newline characters were removed from the fasta file.
