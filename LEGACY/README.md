# 四体 - shitai
# Deprecated

Basic gameplay features are all completed with the exceptions of:
- ~~Timer (How did I forget this?)~~
- SRS spin
- ~~SRS rotation collision~~ (new bug came out, please read Release ~~2~~ 3 patch notes)
- Scoring system
- ~~Show Next Block~~
- Sound & Music
- Revamped proper Graphics
- Video/GIF (clipped texture) for scoring pop-ups
- Menu and Customization using FStream
- Multiplayer(?)

Project started on 1st August 2018 with on/off study and practice of SDL from 2 weeks prior.
Project completed (basic game features) as of 3rd August 2018, new goals set up since project completion.
- Develop easily accessible API
- Interface self-built neural network to play game
- (^Con't) Write report on best block placement based on experienced AI player.

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

Project has been resumed after 1 year hiatus from programming on the 4th of May, 2020.
Learnt how to use GNU Make to compile so I am no longer reliant on IDE.
Took 2 days due to difficult to understand documentation and migration to Atom on Ubuntu

**2 days**

I will spend the next few days studying and thinking how to rewrite the code.
Everything needs to be drawn from a sprite sheet instead of importing a full background png.
At this stage, I do not understand most of the code due to poor documentation, some offsets seem like rubbish to me.
I block seems to be buggy doing rotation when it is sandwiched between another I block and a wall in a 3 blocks gap.



# References
https://tetris.wiki/

http://lazyfoo.net/tutorials/SDL/

http://nuclear.mutantstargoat.com/articles/make/

https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet
