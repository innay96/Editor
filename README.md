# Editor- Exercise 2 in Advanced cpp course

In this exercise we partialy implemented an editor (which is added to this day in Linux) 

Class Editor is the user interface and class Document is for the actual editing.

##

# Command Meaning
**p** prints the current line (ed maintains a current line)

**n** prints line number of current line followed by TAB followed by current line

**%p** prints all lines

**7** makes line #7 the current line

**a** appends new text after the current line

**i** inserts new text before the current line

**c** changes the current line for text that follows

**d** deletes the current line

**/text** searches forward after current line for the specified text. The search wraps to the
beginning of the buffer and continues down to the current line, if necessary

**s/old/new/** replaces old string with new in current line (google: C++ split or token)

**Q** Quits the editor without saving

