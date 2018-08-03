# 四体 - shitai

# Report
C++ is difficult due to manual clearing of memory as well as absence of multiple convenient functions available in modern programming languages, an example of where we can see this is in function "checkClearRow()".

This part took so long because C++ doesn't have a lot of useful functions I am used to and manually checking and replacing elements require a lot of loops which really confused me (until I had a good night sleep and solved it the next morning).
{2 hours}

SRS is also difficult to implement due to me not having much experiences in programming with matrices and rotation matrix was really difficult to understand especially when I have not done any non-basic maths in 2 years.

Resultant matrix COUNTER-CLOCKWISE (unsure if SDL's negative Y-axis has a part in direction) rotation equations = 

x' = -(y - yOrigin) + xOrigin
y' = x - xOrigin + yOrigin

This part took me so long because I keep messing up the equation with "x' = -(y - xOrigin) + xOrigin" and implementing I-block SRS rotation took another 30mins.
{8 hours}
