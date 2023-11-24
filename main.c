// #include "libs/DSU/DSUkelompokteman.h"
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
#include "libs/feature/balasan.h"
#include "libs/feature/kelompokteman.h"

int main()
{
    boolean programStart = true;

    initDatabase();
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                               ::\n");
    printf("                        .^.    :!?7~.             :~!77!~.\n");
    printf("                       .^~77~. :!JY5YJ7^.      :~?JJJJJJJJ7:   \n");
    printf("                       :!??JJJ7??Y555555Y?!^.^7JJJJJJJJ?!!7J!     \n");
    printf("                        :!JJJJJJJJY55555555YJJJJJJJJJJ?:...~J?:      \n");
    printf("                          :!JJJJJJJJJY5YYJJJJJJJJJJJJJ?:...~JJJ!^:.  \n");
    printf("                            .!?JJJJJJJJJJJJJJJJJJJJJJJJ?!~!JJJJJ?7^  \n");
    printf("                              .~?JJJJJJJJJJJJJJJJJJJJJJJJJJJJJ~:.    \n");
    printf("  ..                           .^7JJJJJJJJJJJJJJJJJJJJJJJJJJJJ:      \n");
    printf("   .:^:                    .:~7?JJJJJJJJJJJJJJJJJJJJJJJJJJJJ?:        \n");
    printf("     .~7!~:..        ..:^~7?JJJJJJJJJJJJJJJJJJJJ?7!!~~~~!7J?.         \n");
    printf("       .~?JJ??777777??JJJJJJJJJJJJJJJJJJJJJJJ7!~^^^^^^^^^^^.          \n");
    printf("          ^7JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ?!~^^^^^^^^^^^^.            \n");
    printf("            :~?JJJJJJJJJJJJJJJJJJJJJJJJJJ7^^^^^^^^^^^^^:              \n");
    printf("               :!?JJJJJJJJJJJJJJJJJJJJJ?~^^^^^^^^^^^^:.               \n");
    printf("                 .:~7JJJJJJJJJJJJJJJJJJ~^^^^^^^^^^^:.                 \n");
    printf("                     .^~7?JJJJJJJJJJJJ?^^^^^^^^^:.                    \n");
    printf("                          .:^~!!77?????7^^^::..                       \n");
    printf("                                    .....                             \n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    printf(".______    __    __  .______      .______    __  .______      \n");
    printf("|   _  \\  |  |  |  | |   _  \\     |   _  \\  |  | |   _  \\     \n");
    printf("|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |    \n");
    printf("|   _  <  |  |  |  | |      /     |   _  <  |  | |      /     \n");
    printf("|  |_)  | |  `--'  | |  |\\  \\----.|  |_)  | |  | |  |\\  \\----.\n");
    printf("|______/   \\______/  | _| `._____||______/  |__| | _| `._____|\n");
    printf("\nSelamat datang di BurBir.\n");
    printf("Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode (pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n\n");

    boolean loadSucces = load(true);

    if (!loadSucces)
    {
        printf("Folder tidak ditemukan, program akan berhenti\n\n");
        programStart = false;
    }
    
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
            createNewUtas(wordToInt(currentWord));
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
        else if (isWordEqual(currentWord, stringToWord("BALAS")))
        {
            balas();
        }
        else if (isWordEqual(currentWord, stringToWord("BALASAN")))
        {
            displayBalasan();
        }
        else if (isWordEqual(currentWord, stringToWord("HAPUS_BALASAN")))
        {
            hapusBalasan();
        }
        else if (isWordEqual(currentWord, stringToWord("KELOMPOK_TEMAN")))
        {
            printKelompokTeman();
        }

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