from PIL import Image, ImageDraw, ImageFont
import random

# Daftar quotes default yang bisa dipilih
default_quotes = [
    "Hidup ini adalah pilihan.",
    "Kegagalan adalah awal dari kesuksesan.",
    "Jangan pernah berhenti belajar.",
    "Waktu adalah hal terberharga.",
    "Keberanian bukan berarti tidak ada rasa takut, tapi melangkah meski takut.",
    "Mimpi tidak akan berarti apa-apa jika tidak diikuti dengan usaha."
]

# Fungsi untuk membuat gambar dengan quote
def generate_quote_image(quote, output_path='quote_image.png'):
    # Ukuran gambar
    width, height = 800, 400
    background_color = (255, 223, 186)  # Warna background cream

    # Membuat gambar baru dengan ukuran dan warna background
    img = Image.new('RGB', (width, height), color=background_color)

    # Menambahkan teks ke gambar
    draw = ImageDraw.Draw(img)

    # Menentukan font dan ukuran
    try:
        font = ImageFont.truetype("arial.ttf", 40)  # Pastikan fontnya ada
    except IOError:
        font = ImageFont.load_default()

    # Menghitung ukuran teks untuk penempatan tengah
    text_bbox = draw.textbbox((0, 0), quote, font=font)
    text_width = text_bbox[2] - text_bbox[0]  # Lebar teks
    text_height = text_bbox[3] - text_bbox[1]  # Tinggi teks

    # Menghitung posisi teks agar berada di tengah gambar
    position = ((width - text_width) // 2, (height - text_height) // 2)

    # Menambahkan teks ke gambar
    draw.text(position, quote, fill=(0, 0, 0), font=font)

    # Menyimpan gambar ke file
    img.save(output_path)
    print(f"Quote berhasil dibuat dan disimpan di {output_path}")

# Fungsi untuk memilih quote secara manual atau acak
def get_quote_input():
    print("Pilih salah satu opsi:")
    print("1. Masukkan quote sendiri")
    print("2. Pilih quote secara acak")
    choice = input("Masukkan pilihan (1 atau 2): ")

    if choice == "1":
        # Input quote manual dari pengguna
        quote = input("Masukkan quote Anda: ")
    elif choice == "2":
        # Pilih quote acak dari daftar
        quote = random.choice(default_quotes)
        print(f"Quote yang dipilih secara acak: {quote}")
    else:
        print("Pilihan tidak valid! Menggunakan quote acak.")
        quote = random.choice(default_quotes)

    return quote

# Fungsi utama untuk membuat gambar dengan quote
def generate_random_quote_image():
    quote = get_quote_input()  # Mendapatkan quote dari pengguna
    generate_quote_image(quote)  # Membuat gambar dengan quote yang dipilih

# Menjalankan program
if __name__ == '__main__':
    generate_random_quote_image()
