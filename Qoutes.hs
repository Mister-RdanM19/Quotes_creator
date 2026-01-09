import Graphics.Gloss
import System.Random
import Control.Monad (replicateM)

-- Daftar quotes default
quotes :: [String]
quotes = [
    "Hidup ini adalah pilihan.",
    "Kegagalan adalah awal dari kesuksesan.",
    "Jangan pernah berhenti belajar.",
    "Waktu adalah hal terberharga.",
    "Keberanian bukan berarti tidak ada rasa takut, tapi melangkah meski takut.",
    "Mimpi tidak akan berarti apa-apa jika tidak diikuti dengan usaha."
  ]

-- Fungsi untuk memilih quote secara acak
randomQuote :: IO String
randomQuote = do
    idx <- randomRIO (0, length quotes - 1)
    return (quotes !! idx)

-- Fungsi untuk menggambar quote
drawQuote :: String -> Picture
drawQuote quote = 
    let textPic = Scale 0.2 0.2 $ Text quote
        background = color (makeColor 1 0.874 0.733 1) $ rectangleSolid 800 400
    in Pictures [background, textPic]

-- Fungsi utama untuk menampilkan gambar dengan quote
main :: IO ()
main = do
    quote <- randomQuote
    display (InWindow "Quote Maker" (800, 400) (100, 100)) white (drawQuote quote)
