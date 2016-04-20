using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaseLib
{
    
    public enum MessageType :byte
    {
        ACK = 0x01,
        Start = 0x02,
        Move = 0x03,
        MoveAccepted = 0x04,
        MoveDenied = 0x05,
    }
    [Serializable]
    public struct Packet
    {
        public byte protocol;
        public MessageType type;
        public string gameId;
        public int packetID;
        public string from;
        public string to;
    }
}
