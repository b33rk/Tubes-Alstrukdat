#include "libs/machine/wordmachine.h"
#include "database/database.h"
#include "libs/feature/userfeature.h"
#include "libs/feature/profile.h"
#include "libs/feature/friendshipfeature.h"
#include "libs/feature/friendshipreqfeature.h"
#include "libs/feature/kicauan.h"
#include "libs/feature/draft.h"
#include "libs/feature/loadsave.h"
#include "libs/feature/utasfeature.h"

int main()
{
    boolean programStart = true;

    initDatabase();

    printf(".______    __    __  .______      .______    __  .______      \n");
    printf("|   _  \\  |  |  |  | |   _  \\     |   _  \\  |  | |   _  \\     \n");
    printf("|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |    \n");
    printf("|   _  <  |  |  |  | |      /     |   _  <  |  | |      /     \n");
    printf("|  |_)  | |  `--'  | |  |\\  \\----.|  |_)  | |  | |  |\\  \\----.\n");
    printf("|______/   \\______/  | _| `._____||______/  |__| | _| `._____|\n");
    printf("\nSelamat datang di BurBir.\n");
    printf("Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode (pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n\n");

    load(true);
    while (programStart)
    {

        printf("\n>> ");
        STARTWORD();

        if (isWordEqual(currentWord, stringToWord("TUTUP_PROGRAM")))
        {
            programStart = false;
        }
        else if (isWordEqual(currentWord, stringToWord("DAFTAR")))
        {
            registerUser();
        }
        else if (isWordEqual(currentWord, stringToWord("MASUK")))
        {
            loginUser();
        }
        else if (isWordEqual(currentWord, stringToWord("KELUAR")))
        {
            logoutUser();
        }
        else if (isWordEqual(currentWord, stringToWord("LIHAT_PROFIL")))
        {
            ADVWORD();
            seeProfile(currentWord);
        }
        else if (isWordEqual(currentWord, stringToWord("GANTI_PROFIL")))
        {
            changeProfile();
        }
        else if (isWordEqual(currentWord, stringToWord("ATUR_JENIS_AKUN")))
        {
            changeAccountType();
        }
        else if (isWordEqual(currentWord, stringToWord("UBAH_FOTO_PROFIL")))
        {
            changeProfilePicture();
        }
        else if (isWordEqual(currentWord, stringToWord("DAFTAR_TEMAN")))
        {
            friendlist();
        }
        else if (isWordEqual(currentWord, stringToWord("HAPUS_TEMAN")))
        {
            deleteFriend();
        }
        else if (isWordEqual(currentWord, stringToWord("TAMBAH_TEMAN")))
        {
            addFriend();
        }
        else if (isWordEqual(currentWord, stringToWord("DAFTAR_PERMINTAAN_PERTEMANAN")))
        {
            friendshipReqList();
        }
        else if (isWordEqual(currentWord, stringToWord("SETUJUI_PERTEMANAN")))
        {
            acceptFrienship();
        }
        else if (isWordEqual(currentWord, stringToWord("KICAU")))
        {
            publishKicauan();
        }
        else if (isWordEqual(currentWord, stringToWord("KICAUAN")))
        {
            displayKicauan();
        }
        else if (isWordEqual(currentWord, stringToWord("SUKA_KICAUAN")))
        {
            ADVWORD();
            likeKicauan(wordToInt(currentWord));
        }
        else if (isWordEqual(currentWord, stringToWord("UBAH_KICAUAN")))
        {
            ADVWORD();
            updateKicauan(wordToInt(currentWord));
        }
        else if (isWordEqual(currentWord, stringToWord("BUAT_DRAF")))
        {
            buatdraft(false);
        }
        else if (isWordEqual(currentWord, stringToWord("LIHAT_DRAF")))
        {
            lihatdraft();
        }
        else if (isWordEqual(currentWord, stringToWord("MUAT")))
        {
            load(false);
        }
        else if (isWordEqual(currentWord, stringToWord("SIMPAN")))
        {
            save();
        }
        else if (isWordEqual(currentWord, stringToWord("UTAS")))
        {
            ADVWORD();
            makeUtas(wordToInt(currentWord));
        }
        else if (isWordEqual(currentWord, stringToWord("CETAK_UTAS")))
        {
            ADVWORD();
            cetakUtas(wordToInt(currentWord));
        }
        else if (isWordEqual(currentWord, stringToWord("SAMBUNG_UTAS")))
        {
            ADVWORD();
            int idUtas = wordToInt(currentWord);
            ADVWORD();
            int index = wordToInt(currentWord);
            sambungUtas(idUtas, index);
        }
        else if (isWordEqual(currentWord, stringToWord("HAPUS_UTAS")))
        {
            ADVWORD();
            int idUtas = wordToInt(currentWord);
            ADVWORD();
            int index = wordToInt(currentWord);
            hapusUtas(idUtas, index);
        }
        // else if (isWordEqual(currentWord, stringToWord("BALAS")))
        // {
        //     ADVWORD();
        //     int idKicau = wordToInt(currentWord);
        //     ADVWORD();
        //     int idBalasan = wordToInt(currentWord);
        //     balas(idKicau, idBalasan);
        // }
        // else if (isWordEqual(currentWord, stringToWord("BALASAN")))
        // {
        //     ADVWORD();
        //     balasan(wordToInt(currentWord));
        // }

        printf("\n");
    }

    // save();

    printf(" ______  ____  ____  ________  ______  ____  ____  ________  \n");
    printf("|_   _ \\|_  _||_  _||_   __  ||_   _ \\|_  _||_  _||_   __  | \n");
    printf("  | |_) | \\ \\  / /    | |_ \\_|  | |_) | \\ \\  / /    | |_ \\_| \n");
    printf("  |  __'.  \\ \\/ /     |  _| _   |  __'.  \\ \\/ /     |  _| _  \n");
    printf(" _| |__) | _|  |_    _| |__/ | _| |__) | _|  |_    _| |__/ | \n");
    printf("|_______/ |______|  |________||_______/ |______|  |________| \n");

    printf("\nAnda telah keluar dari program BurBir. \n");
    printf("Sampai jumpa di penjelajahan berikutnya.\n");

    return 0;
}