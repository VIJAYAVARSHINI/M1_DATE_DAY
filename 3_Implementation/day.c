/**
 * @file day.h
 * @author VIJAYA VARSHINI K
 * @brief Validating the day of the week, for a given date along with a message and a book suggession
 * @version 0.1
 * @date 2022-03-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#if defined STDC_LIB_EXT1
#endif


#define COUNT 100
#define RANGE 75
int validateDate(int d, int m, int y)
{
    //check year validity
    if (y >= 1800 && y <= 2999) {
        //check month validity
        if (m >= 1 && m <= 12) {
            //check day validity
            if (d >= 1 && d <= 31) {
                if ((d >= 1 && d <= 30) && (m == 4 || m == 6 || m == 9 || m == 11))
                    return 1; //valid date
                else if ((d >= 1 && d <= 31) && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
                    return 1; //valid date
                else if ((d >= 1 && d <= 28) && (m == 2))
                    return 1; //valid date
                else if (d == 29 && m == 2 && ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)))
                    return 1; //valid date
                else
                    return 0; //invalid day
            }
            else {
                return 0; //day is invalid
            }
        }
        else {
            return 0; //month is invalid
        }
    }
    else {
        return 0; //year is invalid
    }
}
// This function will return week day number from 0 to 6
int wd(int year, int month, int day)
{
    int wday = 0;
    wday = (day + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5)
        + (365 * (year + 4800 - ((14 - month) / 12)))
        + ((year + 4800 - ((14 - month) / 12)) / 4)
        - ((year + 4800 - ((14 - month) / 12)) / 100)
        + ((year + 4800 - ((14 - month) / 12)) / 400)
        - 32045)
        % 7;
    return wday;
}

int main()
{
    int day, month, year;
    int wDayNo = 0;
    char dayNames[][200] = { "Monday\n\nMonday is for people with a mission.\n ",
     "Tuesday\n\nTuesday isn’t so bad…It’s a sign that I’ve somehow survived Monday.\n",
    "Wednesday\n\nToday can be the Hump Day or a day to remember. Your choice.\n",
    "Thursday\n\nIt's Thankful Thursday.\n",
    "Friday\n\nHave a Fulfilling Friday!\n",
    "Saturday\n\nSaturday night is perfect for writers because other people have plans.\n",
    "Sunday\n\nA Sunday well spent brings a week of content.\n" };

    //input date
    printf("Input date (DD-MM-YYYY): ");
    scanf("%d-%d-%d", &day, &month, &year);

    //check date is correct or not
    if (validateDate(day, month, year) == 1) {
        printf("The Date is correct [%02d/%02d/%02d].\n", day, month, year);
        //get weekday number
        wDayNo = wd(year, month, day);
        //print weekday according to wDayNo
        printf("The day is: %s\n", dayNames[wDayNo]);
    }
    else
        printf("The Date is incorrect.\n");
    char* tune[COUNT] = {
        "Pride and Prejudice", "To Kill a Mockingbird", "The Great Gatsby", "One Hundred Years of Solitude",
        "In Cold Blood", "Wide Sargasso Sea", "Brave New World", "I Capture The Castle",
        "Jane Eyre", "Crime and Punishment", "The Secret History", "The Call of the Wild",
        "The Chrysalids", "Persuasion", "Moby-Dick", "The Lion, the Witch and the Wardrobe",
        "To the Lighthouse", "The Death of the Heart", "Tess of the d'Urbervilles", "Frankenstein"
        "The Master and Margarita","The Go-Between","One Flew Over the Cuckoo's Nest", "Nineteen Eighty-Four",
        "Buddenbrooks", "The Grapes of Wrath", "Beloved", "The Code of the Woosters",
        "Dracula", "The Lord of the Rings", "The Adventures of Huckleberry Finn", "Great Expectations",
        "Catch-22", "The Age of Innocence", "Things Fall Apart", "Middlemarch",
        "Midnight's Children", "The Iliad", "Vanity Fair", "Brideshead Revisited"
        "The Catcher in the Rye", "Alice’s Adventures in Wonderland", "The Mill on the Floss", "Barchester Towers",
        "Another Country", "Les Miserables", "Charlie and the Chocolate Factory", "The Outsiders",
        "The Count of Monte Cristo", "Ulysses", "East of Eden", "The Brothers Karamazov",
        "Lolita", "The Secret Garden", "Scoop", "A Tale of Two Cities",
        "Diary of a Nobody", "Anna Karenina", "The Betrothed", "Orlando"
        "Atlas Shrugged", "The Time Machine", "The Art of War", "The Forsyte Saga",
        "Travels with Charley", "Tropic of Cancer", "Women in Love", "Staying On",
        "The Wind in the Willows", "My Ántonia", "Wuthering Heights", "Perfume",
        "War and Peace", "Of Human Bondage", "Bleak House", "Lost Illusions",
        "Breakfast of Champions", "A Christmas Carol", "Silas Marner", "Mrs Dalloway"
        "Little Women", "The Sea, The Sea", "The Godfather", "The Castle",
        "I, Claudius", "Peter Pan", "A Confederacy of Dunces", "The Razor's Edge",
        "Lark Rise to Candleford", "The Return of the Native", "A Portrait of the Artist as a Young Man", "Heart of Darkness",
        "North and South", "The Handmaid's Tale", "Suite Francaise", "One Day in the Life of Ivan Denisovich",
        "What A Carve Up!", "Zen and the Art of Motorcycle Maintenance", "White Nights", "Hard Times"

    };

    int recent[COUNT];
    int t, you, cycle, found;

    /* initialize stuff */
    srand((unsigned)time(NULL));	/* seed the randomizer */
    for (t = 0;t < COUNT;t++)
    
    cycle = 0;						/* counts to 100 */

    while (cycle < 100)
    {
        do
        {
            you = rand() % COUNT;
            found = 0;
            for (t = 0;t < RANGE;t++)
            {
                if (recent[t] == you)
                    found = 1;
            }
        } 
        while (found);
        printf("Have a Nice Day! Your book suggestion is %d) %s\n",cycle + 1, tune[you]);
        break;

    }


    return 0;
}
