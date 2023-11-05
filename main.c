#include "libs/machine/wordmachine.h"
#include "database/database.h"
#include "libs/feature/userfeature.h"
#include "libs/feature/profile.h"

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

    while (programStart)
    {

        printf("\n>> ");
        STARTWORD();

        // printf("input: ");
        // printWord(currentWord);
        // printf("\n");

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
        else if (isWordEqual(currentWord, stringToWord("KELUAR"))){
            logoutUser();
        }
        else if (isWordEqual(currentWord, stringToWord("LIHAT_PROFIL"))){
            ADVWORD();
            seeProfile(currentWord);
        } else if (isWordEqual(currentWord, stringToWord("GANTI_PROFIL"))){
            changeProfile();
        } else if (isWordEqual(currentWord, stringToWord("ATUR_JENIS_AKUN"))){
            changeAccountType();
        } else if (isWordEqual(currentWord, stringToWord("UBAH_FOTO_PROFIL"))){
            changeProfilePicture();
        }

        printf("\n");

        // printUser(currentUser);
    }

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