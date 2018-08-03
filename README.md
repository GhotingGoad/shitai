# 四体 - shitai

Basic gameplay features are all completed with the exceptions of:
- SRS spin
- SRS rotation collision
- Scoring system
- Show Next Block
- Sound & Music
- Revamped proper Graphics
- Video/GIF (clipped texture) for scoring pop-ups
- Menu
- Multiplayer(?)

# Report
### Absence of Useful Functions & Clearing Lines in C++
C++ is difficult due to manual clearing of memory as well as absence of multiple convenient functions available in modern programming languages, an example of where we can see this is in function "checkClearRow()".

This part took so long because C++ doesn't have a lot of useful functions I am used to and manually checking and replacing elements require a lot of loops which really confused me (until I had a good night sleep and solved it the next morning).
**2 hours**

### SRS and Rotation Matrix
SRS is also difficult to implement due to me not having much experiences in programming with matrices and rotation matrix was really difficult to understand especially when I have not done any non-basic maths in 2 years.

Resultant matrix __counter-clockwise__ (unsure if SDL's negative Y-axis has a part in direction) rotation equations = 

x' = -(y - yOrigin) + xOrigin

y' = x - xOrigin + yOrigin

This part took me so long because I keep messing up the equation with "x' = -(y - xOrigin) + xOrigin" and implementing I-block SRS rotation took another 30mins.
**8 hours**

# References
https://tetris.wiki/
