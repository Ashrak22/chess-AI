using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace chess_lib
{
    static class Extensions
    {
        public static string MyToString(this COLOUR colour)
        {
            switch (colour)
            {
                case COLOUR.WHITE:
                    return "WHITE";
                case COLOUR.BLACK:
                    return "BLACK";
                default:
                    return "";
            }
        }

        public static string MyToString(this STONES type)
        {
            switch (type)
            {
                case STONES.BISHOP:
                    return "B";
                case STONES.EMPTY:
                    return " ";
                case STONES.KING:
                    return "G";
                case STONES.KNIGHT:
                    return "K";
                case STONES.PAWN:
                    return "P";
                case STONES.QUEEN:
                    return "Q";
                case STONES.ROOK:
                    return "R";
                default:
                    return "";
            }
        }
    }
}
