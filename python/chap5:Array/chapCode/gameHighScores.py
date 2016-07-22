'''
This chunk is written to store high scores of any application like video game.
This is applicable everywhere any sequence of objects is stored.

Only two values are taken, _score, _name to keep it simple.

Class GameEntry stores the values of a game.
'''

class GameEntry:

    def __init__(self, name, score):
        self._name = name
        self._score = score

    def getName(self):
        return self._name

    def getScore(self):
        return self._score

    def __str__(self):
        return '({0},{1})'.format(self._name, self._score)

'''
Class for high scores
A new high score will be inducted if and only if it is greater than the lowest
score on the table.
The size of scoreboard is game specific, so it is put into constructor.
'''

class HighScores:

    def __init__(self, capacity = 10):
        self._board = [None]*capacity
        self._capacity = capacity
        self._n = 0

    def __getitem__(self,k):
        return _board[k]

    def __str__(self):
        return '\n'.join(str(self._board[j]) for j in range(self._n))

    def add(self, entry):
        score = entry.getScore()
        good = self._n < self._capacity or entry.getScore() > self._board[-1].getScore()

        if good:
            if self._n < self._capacity:
                self._n += 1

            j = self._n - 1
            while j > 0 and self._board[j-1].getScore() < entry.getScore():
                self._board[j] = self._board[j-1]
                j -= 1
            self._board[j] = entry

leaderBoard = HighScores(3)

user1 = GameEntry('user1', 12)
leaderBoard.add(user1)
print (1,'\n',str(leaderBoard))

user2 = GameEntry('user2', 13)
leaderBoard.add(user2)
print (2,'\n',str(leaderBoard))

user3 = GameEntry('user3', 14)
leaderBoard.add(user3)
print (3,'\n',str(leaderBoard))

user4 = GameEntry('user4', 13)
leaderBoard.add(user4)
print (4,'\n',str(leaderBoard))
