// enum png {
//     sign = '89 50 4E 47 0D 0A 1A 0A',
//     IHDR = '00 00 00 0D 49 48 44 52 00 00 00 01 00 00 00 01 08 02 00 00 00 90 77 53 DE',
//     // IDAT = '',
//     IEND = '00 00 00 00 49 45 4E 44 AE 42 60 82'
// };

// PLTE contains the palette: a list of colors.

// The IHDR chunk must appear FIRST. It contains:

//    Width:              4 bytes
//    Height:             4 bytes
//    Bit depth:          1 byte
//    Color type:         1 byte
//    Compression method: 1 byte
//    Filter method:      1 byte
//    Interlace method:   1 byte

//    Color    Allowed    Interpretation
//    Type    Bit Depths
   
//    0       1,2,4,8,16  Each pixel is a grayscale sample.
   
//    2       8,16        Each pixel is an R,G,B triple.
   
//    3       1,2,4,8     Each pixel is a palette index;
//                        a PLTE chunk must appear.
   
//    4       8,16        Each pixel is a grayscale sample,
//                        followed by an alpha sample.
   
//    6       8,16        Each pixel is an R,G,B triple,
//                        followed by an alpha sample.


typedef struct chunk{
    int length;
    char chunk_type;
    int chunk_data;
    int crc;
}chunk;