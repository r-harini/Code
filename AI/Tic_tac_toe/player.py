import math
import random

class Player():
    def __init__(self, letter):
        self.letter = letter

    def get_move(self, game):
        pass

class HumanPlayer(Player):
    def __init__(self, letter):
        super().__init__(letter)

    def get_move(self,game):
        valid_square=False
        val=None
        while not valid_square:
            sqaure=input(self.letter +'\'s turn. Input move (0-9):')
            try:
                val=int(sqaure)
                if val not in game.available_moves():
                    raise ValueError
                valid_square=True
            except ValueError:
                print('Invalid square. Try again')
        return val

class RandomComputerPlayer(Player):
    def __init__(self, letter):
        super().__init__(letter)

    def get_move(self, game):
        square = random.choice(game.available_moves())
        return square

class SmartComputerPlayer(Player):
    def __init__(self, letter):
        super().__init__(letter)

    def get_move(self, game):
        if (len(game.available_moves))==9:
            square=random.choice(game.available_moves())
        else:
            square=self.minimax(game, self.letter)['position']