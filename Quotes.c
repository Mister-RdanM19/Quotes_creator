#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include <time.h>

// Daftar quotes
const char *quotes[] = {
    "Hidup ini adalah pilihan.",
    "Kegagalan adalah awal dari kesuksesan.",
    "Jangan pernah berhenti belajar.",
    "Waktu adalah hal terberharga.",
    "Keberanian bukan berarti tidak ada rasa takut, tapi melangkah meski takut.",
    "Mimpi tidak akan berarti apa-apa jika tidak diikuti dengan usaha."
};

#define NUM_QUOTES 6
#define WIDTH 800
#define HEIGHT 400

int main() {
    // Inisialisasi SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL gagal diinisialisasi: %s\n", SDL_GetError());
        return -1;
    }

    // Inisialisasi SDL_ttf untuk font
    if (TTF_Init() == -1) {
        printf("SDL_ttf gagal diinisialisasi: %s\n", TTF_GetError());
        return -1;
    }

    // Membuka jendela SDL
    SDL_Window *window = SDL_CreateWindow("Quote Maker", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Gagal membuka jendela: %s\n", SDL_GetError());
        return -1;
    }

    // Membuat renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Gagal membuat renderer: %s\n", SDL_GetError());
        return -1;
    }

    // Memilih font
    TTF_Font *font = TTF_OpenFont("arial.ttf", 40);
    if (!font) {
        printf("Gagal membuka font: %s\n", TTF_GetError());
        return -1;
    }

    // Memilih quote acak
    srand(time(NULL));
    const char *quote = quotes[rand() % NUM_QUOTES];

    // Membuat surface dan texture untuk gambar
    SDL_Surface *surface = TTF_RenderText_Blended(font, quote, (SDL_Color){0, 0, 0});
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    // Mendapatkan ukuran teks
    int text_width = surface->w;
    int text_height = surface->h;
    SDL_FreeSurface(surface);

    // Menyusun posisi teks di tengah
    SDL_Rect dstrect = { (WIDTH - text_width) / 2, (HEIGHT - text_height) / 2, text_width, text_height };

    // Menampilkan background (cream)
    SDL_SetRenderDrawColor(renderer, 255, 223, 186, 255); // Background cream
    SDL_RenderFillRect(renderer, NULL);

    // Menampilkan teks
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_RenderPresent(renderer);

    // Menunggu sebelum keluar
    SDL_Delay(5000);

    // Bersihkan dan tutup SDL
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
