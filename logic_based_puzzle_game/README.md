# Logic based puzzle game

https://leetcode.com/discuss/interview-question/395615/Microsoft-2019-or-Online-Assessment-or-Logic-based-puzzle-game

Mark is fan of logic based games. However he is bored of the basic ones, like Sudoku and Mastermind, since he has solved so many of them. Recently he found a new game in which one is given a string with some question marks in it. The objective is to replace all of the question marks with letters(one letter per question mark) in such a way that no letters appears next to another letter of the same kind.

Write a function:

    string solution(string & s);

that given a string puzzle, returns a copy of the string with all the question marks replaced by lowercase letters(a-z) in such a way that the same letters do not occur next to each other. The result can be any of the possible answers as long as it fulfils the above requirements.

Examples:

    Given puzzle = 'xy?xz?', your function might return 'xycxza'. 
    Some other possible results are 'xyzxzd', 'xyfxzf'.

    Given puzzle = 'ab?e?mr??'. Your function might return 'abveamrab'

    Given puzzle = '??????'. Your function might return 'league'

Write an efficient algorithm for the following assumptions:

    String puzzle contains only of lowercase letters(a-z) or '?'
    It is always possible to turn string 'puzzle' into a string without two identical consecutive letters
 
