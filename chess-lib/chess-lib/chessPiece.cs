using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace chess_lib
{
    public enum STONES
    {
        EMPTY = 0,
        PAWN = 1,
		KNIGHT = 2,
		BISHOP = 3,
		ROOK = 4,
		QUEEN = 5,
		KING = 6
    }

    public enum COLOUR
    {
        NONE = 0,
        BLACK = 1,
		WHITE = 2
    }

    class chessPiece
    {
        public COLOUR colour { get; private set; }
        public STONES type { get; private set; }

        chessPiece(chessPiece orig = null)
        {
            if(orig == null)
            {
                colour = orig.colour;
                type = orig.type;
            }
            else
            {
                colour = COLOUR.NONE;
                type = STONES.EMPTY;
            }
        }
        chessPiece(COLOUR orig, STONES stone)
        {
            colour = orig;
            type = stone;
        }

        void set(chessPiece orig)
        {
            set(orig.colour, orig.type);
        }
        void set(COLOUR orig, STONES stone)
        {
            colour = orig;
            type = stone;
        }        
        void clear()
        {
            type = STONES.EMPTY;
            colour = COLOUR.NONE;
        }

        public override string ToString()
        {
            return type.MyToString();
        }
    }
}
