# Sorting-PAMSI (designing algorithms and AI methods)
Program written as part of the studies at Wroclaw University of Science and Technology

Program destined to sort movies (or any other data) by their rank in an ascending order from data file with very specific format using 3 different algorithms.

The ranking field is known to be either empty or an intiger within the range 0 to 10.

The UI is all in console and in Polish language as well as comments in code, but variables, functions, etc. are in English.

# Used sorting algorithms:
- bucket sort
- quicksort
- merge sort

# Input data file format:

```
id,movie,rating
0,After Life (2019– ),9.0
1,The Valhalla Murders (2019– ),6.0
.
.
.

```

**NOTE:**  
- input file have to be named *dane.csv*  
- comma is the only possible separator  
- ratings have to end with *.0*  
- first line is ignored

# Output

A file *dane_posortowane_.csv* with as many sorted movies as user chooses is created. The output file has the same format as the input file.
What's more, time the algorithm took to sort data, median rating and average rating are written to standart output (into the console).
