

/*
   how to deal with moving holidays...
  for (y = 2021; y < 2031; y++) {
  if (y == theYear) {
    if (theDay == easter[y - 2021]) {

    }
  }
  }
*/


void holidate(byte theMon, byte theDay, byte theHour, byte theMin) {

  switch (theMon) {
    case 1: // January
      switch (theDay) {
        case 1:  strcpy(timePhrase, PSTR("        HAPPY NEW YEAR          "));
          break; ni
        case 2:  strcpy(timePhrase, PSTR("        HAPPY NYINLONG          "));
          break;
        case 3:  strcpy(timePhrase, PSTR("  HAPPY BIRTHDAY ANNA MAY WONG  "));
          break;
        case 4:  strcpy(timePhrase, PSTR("HAPPY BIRTHDAY SIR ISAAC NEWTON "));
          break;
        case 5:  strcpy(timePhrase, PSTR("       HAPPY EPIPHANY EVE       "));
          break;
        case 6:  strcpy(timePhrase, PSTR("       FELIZ DIA DE REYES       "));
          break;
        case 7:  strcpy(timePhrase, PSTR("        KALA CHRISTOUGENA       "));
          break;
        case 8:  strcpy(timePhrase, PSTR("  HAPPY BIRTHDAY ELVIS PRESLEY  "));
          break;
        case 13: strcpy(timePhrase, PSTR("    HAPPY OLD NEW YEAR'S EVE    "));
          break;
        case 14: strcpy(timePhrase, PSTR("      HAPPY OLD NEW YEAR        ")); // orthodox new year https://en.wikipedia.org/wiki/Old_New_Year
          break;
        case 15: strcpy(timePhrase, PSTR("   IT IS NATIONAL NOTHING DAY   "));
          break;
        case 16: strcpy(timePhrase, PSTR("MARTIN LUTHER KING JR'S BIRTHDAY"));
          break;
        case 19: strcpy(timePhrase, PSTR("          HAPPY TIMKAT          ")); //https://en.wikipedia.org/wiki/Timkat
          break;
        case 20: strcpy(timePhrase, PSTR("     IT IS INAUGURATION DAY     ")); // check year? (y % 4 == 1)but we gotta pass that through...
          break;
        case 24: strcpy(timePhrase, PSTR("JOLLY BELLY LAUGH DAY   HA HA HA"));
          break;
        case 25: strcpy(timePhrase, PSTR("SLAINTE MHATH   IT'S BURNS NIGHT")); // Sláinte Mhath - Oidhche Bhlas Burns
          break;
        case 27: strcpy(timePhrase, PSTR("IT IS HOLOCAUST REMEMBRANCE DAY "));
          break;
        case 28: strcpy(timePhrase, PSTR("     IT IS DATA PRIVACY DAY     "));
          break;
        case 30: strcpy(timePhrase, PSTR("    IT IS FRED KOREMATSU DAY    ")); // also   // Feliz dia da saudade
          break;
        default:  // if no special day, just show the time
          genTimePhrase(theHour, theMin);
          break;
      }
      break;
    case 2: // February
      switch (theDay) {
        case 1:  strcpy(timePhrase, PSTR("         HAPPY IMBOLC           "));
          break;
        case 2:  strcpy(timePhrase, PSTR("      HAPPY GROUNDHOG DAY       "));
          break;
        case 4:  strcpy(timePhrase, PSTR("     HAPPY ROSA PARKS DAY       "));
          break;
        case 6:  strcpy(timePhrase, PSTR("IT IS ZERO TOLERANCE FOR FGM DAY")); // https://en.wikipedia.org/wiki/International_Day_of_Zero_Tolerance_for_Female_Genital_Mutilation
          break; // also Waitangi Day
        case 8:  strcpy(timePhrase, PSTR("      HAPPY NIRVANA DAY         "));  // Mahayana, most celebrate on the 15th
          break;
        case 11: strcpy(timePhrase, PSTR("     HAPPY INVENTORS' DAY       "));
          break;
        case 12: strcpy(timePhrase, PSTR("       HAPPY DARWIN DAY         "));  // also Lincoln's Birthday
          break;
        case 14: strcpy(timePhrase, PSTR("     HAPPY VALENTINE'S DAY      "));
          break;
        case 15: strcpy(timePhrase, PSTR("       HAPPY LUPERCALIA         ")); // also Single's Awareness Day
          break;
        case 19: strcpy(timePhrase, PSTR("DAY OF REMEMBRANCE EX ORDER 9066"));
          break;
        case 21: strcpy(timePhrase, PSTR("        HAPPY FERALIA           ")); // also Nina Simone's birthday
          break;
        case 22: strcpy(timePhrase, PSTR(" GEORGE WASHINGTON'S BIRTHDAY   "));
          break;
        case 23: strcpy(timePhrase, PSTR("IT'S KAZIMIR MALEVICH'S BIRTHDAY")); // also Emperor Naruhito's birthday
          break;
        case 24: strcpy(timePhrase, PSTR("   DRAGOBETELE SARUTA FETELE    "));         // Dragobetele saruta fetele
          break;
        case 26: strcpy(timePhrase, PSTR("   HAPPY BIRTHDAY JOHNNY CASH   "));
          break;
        case 27: strcpy(timePhrase, PSTR("      HAPPY POLAR BEAR DAY      "));
          break;
        case 28: strcpy(timePhrase, PSTR("IT'S PEACE MEMORIAL DAY      228")); // Taiwan
          break;
        case 29: strcpy(timePhrase, PSTR("        HAPPY LEAP DAY          "));
          break;
        default:  // if no special day, just show the time
          genTimePhrase(theHour, theMin);
          break;
      }
      break;
    case 3: // March
      switch (theDay) {
        case 3:  strcpy(timePhrase, PSTR("  HAPPY BIRTHDAY GEORG CANTOR   "));
          break;
        case 5:  strcpy(timePhrase, PSTR(" IT IS LEARN FROM LEI FENG DAY  "));
          break;
        case 8:  strcpy(timePhrase, PSTR("HAPPY INTERNATIONAL WOMEN'S DAY "));
          break;
        case 10: strcpy(timePhrase, PSTR("    HAPPY HARRIET TUBMAN DAY    "));
          break;
        case 12: strcpy(timePhrase, PSTR("     FELIZ ANO NUEVO AZTECA     "));
          break;
        case 14:
          if (theHour == 13 && theMin == 59) { // 1:59 PM
            strcpy(timePhrase, PSTR("        HAPPY PI MINUTE         "));
          } else {
            strcpy(timePhrase, PSTR("          HAPPY PI DAY          ")); // also Einstein's birthday
          }
          break;
        case 15: strcpy(timePhrase, PSTR("   BEWARE THE IDES OF MARCH     "));
          break;
        case 17: strcpy(timePhrase, PSTR("        ERIN GO BRAGH           "));
          break;
        case 19: strcpy(timePhrase, PSTR("     MERRY VERNAL EQUINOX       ")); // can move a bit
          break;
        case 21: strcpy(timePhrase, PSTR("         NOWRUZ MOBARAK         "));
          break;
        case 23: strcpy(timePhrase, PSTR("    IT IS YAUM-E-MASIH MAUD     ")); // https://en.wikipedia.org/wiki/Promised_Messiah_Day
          break;
        case 25: strcpy(timePhrase, PSTR("REMEMBRANCE DAY SLAVERY VICTIMS ")); // https://en.wikipedia.org/wiki/International_Day_of_Remembrance_of_the_Victims_of_Slavery_and_the_Transatlantic_Slave_Trade
          break;
        case 26: strcpy(timePhrase, PSTR("   HAPPY FREE THE NIPPLE DAY    ")); // https://www.internationaldays.co/event/free-the-nipple-day/r/rece4NpmCWxkVnBnx
          break;
        case 27: strcpy(timePhrase, PSTR("HAPPY INTERNATIONAL WHISKEY DAY "));
          break;
        case 30: strcpy(timePhrase, PSTR("         IT IS LAND DAY         "));
          break;
        case 31: strcpy(timePhrase, PSTR("IT IS TRANSGENDER VISIBILITY DAY"));
          break;
        default:  // if no special day, just show the time
          genTimePhrase(theHour, theMin);
          break;
      }
      break;
    case 4: // April
      switch (theDay) {
        case 1:  strcpy(timePhrase, PSTR("BE CAREFUL IT'S APRIL FOOLS DAY ")); // also Assyrian New Year Kha b'Nissan
          break;
        case 5:  strcpy(timePhrase, PSTR("     HAPPY COLD FOOD FESTIVAL   "));
          break;
        case 6:  strcpy(timePhrase, PSTR("         HAPPY TARTAN DAY       ")); // New Beer's Eve
          break;
        case 7:  strcpy(timePhrase, PSTR(" HAPPY BIRTHDAY BILLIE HOLIDAY  "));
          break;
        case 8:  strcpy(timePhrase, PSTR("       HAPPY HANAMATSURI        ")); // https://en.wikipedia.org/wiki/International_Romani_Day
          break;
        case 12: strcpy(timePhrase, PSTR("       HAPPY YURI'S NIGHT       "));
          break;
        case 13: strcpy(timePhrase, PSTR("IT'S THOMAS JEFFERSON'S BIRTHDAY")); // also https://en.wikipedia.org/wiki/Vaisakhi
          break;
        case 14: strcpy(timePhrase, PSTR("EAT JAJANGMYEON   IT'S BLACK DAY")); // https://en.wikipedia.org/wiki/Black_Day_(South_Korea)
          break;                                                               // also https://en.wikipedia.org/wiki/Puthandu Tamil New Year
        case 15: strcpy(timePhrase, PSTR("          HAPPY TAX DAY         ")); // also Lincoln assassination
          break;
        case 19: strcpy(timePhrase, PSTR("        HAPPY BICYCLE DAY       ")); // https://en.wikipedia.org/wiki/History_of_lysergic_acid_diethylamide#%22Bicycle_Day%22
          break;
        case 20: strcpy(timePhrase, PSTR("           HAPPY 4/20           "));
          break;
        case 21: strcpy(timePhrase, PSTR("ABU YE      HAPPY GROUNATION DAY")); // https://en.wikipedia.org/wiki/Grounation_Day
          break;
        case 22: strcpy(timePhrase, PSTR("        HAPPY EARTH DAY         "));
          break;
        case 23: strcpy(timePhrase, PSTR("  HAPPY FEAST OF SAINT GEORGE   "));
          break;
        case 25: strcpy(timePhrase, PSTR("         HAPPY DNA DAY          "));
          break;
        case 26: strcpy(timePhrase, PSTR("  IT IS CHERNOBYL DISASTER DAY  ")); //  International Chernobyl Disaster Remembrance Day
          break;
        case 27: strcpy(timePhrase, PSTR("     GELUKKIGE VRYHEIDSDAG      ")); // Freedom Day South Africa
          break;
        case 28: strcpy(timePhrase, PSTR("     SA DIE DE SA SARDIGNA      ")); // https://en.wikipedia.org/wiki/Sa_die_de_sa_Sardigna - also Tristan Tzara's birthday
          break;
        case 29: strcpy(timePhrase, PSTR("         HAPPY SHOWA DAY        ")); // https://en.wikipedia.org/wiki/Sh%C5%8Dwa_Day
          break;
        case 30: strcpy(timePhrase, PSTR("    FROEHLICHE WALPURGISNACHT   ")); // Arbor day
          break;
        default:  // if no special day, just show the time
          genTimePhrase(theHour, theMin);
          break;
      }
      break;
    case 5: // May
      switch (theDay) {
        case 1:  strcpy(timePhrase, PSTR("         HAPPY MAY DAY          "));
          break;
        case 3:  strcpy(timePhrase, PSTR("   FELIZ FIESTA DE LAS CRUCES   ")); // Roodmas
          break;
        case 4:  strcpy(timePhrase, PSTR("   MAY THE FOURTH BE WITH YOU   "));
          break;
        case 5:  strcpy(timePhrase, PSTR("      FELIZ CINCO DE MAYO       "));
          break;
        case 6:  strcpy(timePhrase, PSTR("HAPPY INTERNATIONAL NO DIET DAY ")); // https://en.wikipedia.org/wiki/International_No_Diet_Day
          break;
        case 7:  strcpy(timePhrase, PSTR("HAPPY DIEN BIEN PHU VICTORY DAY "));
          break;
        case 8:  strcpy(timePhrase, PSTR("  HAPPY VICTORY IN EUROPE DAY   "));
          break;
        case 9:  strcpy(timePhrase, PSTR("        HAPPY EUROPE DAY        ")); // also Ghostface Killah Day
          break;
        case 11: strcpy(timePhrase, PSTR("  HAPPY BIRTHDAY SALVADOR DALI  "));
          break;
        case 13: strcpy(timePhrase, PSTR("1ST RADIO BROADCAST MADE IN 1897")); // https://www.bbc.com/news/uk-england-somerset-61327062
          break;
        case 15: strcpy(timePhrase, PSTR("        IT IS NAKBA DAY         ")); // also Brian Eno's birthday
          break;
        case 17: strcpy(timePhrase, PSTR("    HAPPY BIRTHDAY ERIK SATIE   "));
          break;
        case 19: strcpy(timePhrase, PSTR("      HAPPY MALCOLM X DAY       ")); // https://en.wikipedia.org/wiki/Malcolm_X_Day
          break;
        case 20: strcpy(timePhrase, PSTR(" DAY OF REMEMBRANCE IN CAMBODIA "));
          break;
        case 21: strcpy(timePhrase, PSTR("  DIA DE LA AFROCOLOMBIANIDAD   "));
          break;
        case 22: strcpy(timePhrase, PSTR("     IT IS HARVEY MILK DAY      ")); // also Al-Quds Day - also Sun Ra's birthday
          break;
        case 25: strcpy(timePhrase, PSTR("        HAPPY AFRICA DAY        "));
          break;
        case 28: strcpy(timePhrase, s_manhattanhenge);
          break;
        case 29: strcpy(timePhrase, PSTR("       HAPPY OAK APPLE DAY      "));
          break;
        case 31: strcpy(timePhrase, PSTR("  HAPPY NOTORIOUS B.I.G. DAY    ")); // also https://en.wikipedia.org/wiki/Tulsa_race_massacre
          break;
        default:  // if no special day, just show the time
          genTimePhrase(theHour, theMin);
          break;
      }
      break;
    case 6: // June
      switch (theDay) {
        case 2:  strcpy(timePhrase, PSTR(" INTERNATIONAL SEX WORKERS DAY  "));
          break;
        case 3:  strcpy(timePhrase, PSTR("    HAPPY WORLD BICYCLE DAY     "));
          break;
        case 4:  strcpy(timePhrase, PSTR("  IT IS TIANANMEN MEMORIAL DAY  ")); // "reverse the verdict on June 4"
          break;
        case 5:  strcpy(timePhrase, PSTR("       IT IS NAKSA DAY          "));
          break;
        case 6:  strcpy(timePhrase, PSTR("   THIS DAY IN 1944 WAS D-DAY   "));
          break;
        case 10: strcpy(timePhrase, PSTR("     FELIZ DIA DE PORTUGAL      "));
          break;
        case 11: strcpy(timePhrase, PSTR("  HAPPY KING KAMEHAMEHA I DAY   "));
          break;
        case 12: strcpy(timePhrase, PSTR("        HAPPY LOVING DAY        "));
          break;
        case 14: strcpy(timePhrase, PSTR("        HAPPY FLAG DAY          "));
          break;
        case 16: strcpy(timePhrase, PSTR("        HAPPY BLOOMSDAY         "));
          break;
        case 18: strcpy(timePhrase, PSTR("      HAPPY WATERLOO DAY        "));
          break;
        case 19: strcpy(timePhrase, PSTR("       HAPPY JUNETEENTH         "));
          break;
        case 20: strcpy(timePhrase, PSTR("     HAPPY SUMMER SOLSTICE      ")); // can move a bit
          break;
        case 21: strcpy(timePhrase, PSTR("     HAPPY MAKE MUSIC DAY       "));
          break;
        case 24: strcpy(timePhrase, PSTR("      HAPPY MIDSUMMER DAY       ")); // St John's Day
          break;
        case 25: strcpy(timePhrase, PSTR("   HAPPY ANTHONY BOURDAIN DAY   "));
          break;
        case 26: strcpy(timePhrase, PSTR("    HAPPY RATCATCHER'S DAY      ")); // https://en.wikipedia.org/wiki/Ratcatcher%27s_Day
          break;
        case 27: strcpy(timePhrase, PSTR("    HAPPY HELEN KELLER DAY      ")); // also Emma Goldman's birthday
          break;
        case 28: strcpy(timePhrase, PSTR(" HAPPY STONEWALL LIBERATION DAY ")); // Christopher Street Day - also Franz Ferdinand assassinated
          break;
        case 30: strcpy(timePhrase, PSTR("      HAPPY ASTEROID DAY        "));
          break;
        default:  // if no special day, just show the time
          genTimePhrase(theHour, theMin);
          break;
      }
      break;
    case 7: // July
      switch (theDay) {
        case 1:  strcpy(timePhrase, PSTR("      BONNE FETE DU CANADA      ")); // Bonne Fete du Canada - also H-bomb test in Bikini, 1946
          break;
        case 4:  strcpy(timePhrase, PSTR("     HAPPY INDEPENDENCE DAY     "));
          break;
        case 5:  strcpy(timePhrase, PSTR("         HAPPY BIKINI DAY       "));
          break;
        case 7:  strcpy(timePhrase, PSTR("       HAPPY QIXI FESTIVAL      "));
          break;
        case 10: strcpy(timePhrase, PSTR("     HAPPY NIKOLA TESLA DAY     "));
          break;
        case 13: strcpy(timePhrase, s_manhattanhenge);
          break;
        case 14: strcpy(timePhrase, PSTR("    JOYEUX QUATORZE JUILLET     ")); // Bastille Day
          break;
        case 16: strcpy(timePhrase, PSTR(" TRINITY TEST WAS TODAY IN 1945 ")); // https://en.wikipedia.org/wiki/Trinity_(nuclear_test)
          break;
        case 17: strcpy(timePhrase, PSTR("     HAPPY WORLD EMOJI DAY      "));
          break;
        case 18: strcpy(timePhrase, PSTR("    HAPPY NELSON MANDELA DAY    "));
          break;
        case 22: strcpy(timePhrase, PSTR("   HAPPY PI APPROXIMATION DAY   ")); // 22/7
          break;
        case 23: strcpy(timePhrase, PSTR("HAPPY BIRTHDAY HAILE SELASSIE I "));
          break;
        case 26: strcpy(timePhrase, PSTR("    FELICAN ESPERANTAN TAGON    ")); // feliĉan esperantan tagon
          break;
        case 28: strcpy(timePhrase, PSTR(" HAPPY BIRTHDAY MARCEL DUCHAMP  "));
          break;
        default:  // if no special day, just show the time
          genTimePhrase(theHour, theMin);
          break;
      }
      break;
    case 8: // August
      switch (theDay) {
        case 1:  strcpy(timePhrase, PSTR("        HAPPY LUGHNASA          ")); // Lughnasa also PLA day and Emancipation Day
          break;
        case 2:  strcpy(timePhrase, PSTR("  ROMA HOLOCAUST MEMORIAL DAY   "));
          break;
        case 4:  strcpy(timePhrase, PSTR("      HAPPY BARACK OBAMA DAY    "));
          break;
        case 6:  strcpy(timePhrase, PSTR("        IT IS HIROSHIMA DAY     ")); // also Andy Warhol's birthday
          break;
        case 8:  strcpy(timePhrase, PSTR("NEVER FORGET   THE 8888 UPRISING")); // Burma     also international Cat Day
          break;
        case 9:  strcpy(timePhrase, PSTR("        IT IS NAGASAKI DAY      "));
          break;
        case 12: strcpy(timePhrase, PSTR("        DO WHAT THOU WILT       ")); // Thelema  The Feast of the Prophet and His Bride
          break;
        case 13: strcpy(timePhrase, PSTR(" INTERNATIONAL LEFTHANDERS DAY  "));
          break;
        case 17: strcpy(timePhrase, PSTR("     HAPPY MARCUS GARVEY DAY    "));
          break;
        case 20: strcpy(timePhrase, PSTR(" VOYAGER 2 LAUNCHED TODAY 1977  ")); // https://en.wikipedia.org/wiki/Voyager_2
          break;
        default:  // if no special day, just show the time
          genTimePhrase(theHour, theMin);
          break;
      }
      break;
    case 9: // September
      switch (theDay) {
        case 1:  strcpy(timePhrase, PSTR("WORLD WAR II BEGAN TODAY IN 1939"));
          break;
        case 5:  strcpy(timePhrase, PSTR(" VOYAGER 1 LAUNCHED TODAY 1977  ")); // https://en.wikipedia.org/wiki/Voyager_1
          break;
        case 9:  strcpy(timePhrase, PSTR("  ATTICA ATTICA ATTICA ATTICA   ")); // Attica uprising
          break;
        case 11: strcpy(timePhrase, PSTR("NEVER FORGET                9/11")); // also Enkutatash, Ethiopian/Eritrean New Year
          break;
        case 14: strcpy(timePhrase, PSTR(" HAPPY BIRTHDAY MARGARET SANGER ")); // https://en.wikipedia.org/wiki/Margaret_Sanger
          break;
        case 16: strcpy(timePhrase, PSTR("VIVA LA INDEPENDENCIA DE MEXICO ")); // Mexican Independence Day
          break;
        case 17: strcpy(timePhrase, PSTR("     HAPPY CONSTITUTION DAY     "));
          break;
        case 19: strcpy(timePhrase, PSTR("AHOY ME MATIES     AAAAAARRRRRRR")); // talk like a priate day
          break;
        case 21: strcpy(timePhrase, PSTR("      HAPPY WORLD PEACE DAY     "));
          break;
        case 22: strcpy(timePhrase, PSTR("      HAPPY AUTUMNAL EQUINOX    ")); // can move a bit
          break;
        case 23: strcpy(timePhrase, PSTR(" HAPPY BISEXUAL VISIBILITY DAY  "));
          break;
        default:  // if no special day, just show the time
          genTimePhrase(theHour, theMin);
          break;
      }
      break;
    case 10: // October
      switch (theDay) {
        case 1:  strcpy(timePhrase, PSTR("  IT IS NATIONAL DAY IN CHINA   "));
          break;
        case 2:  strcpy(timePhrase, PSTR("  IT IS VICTORY OVER JAPAN DAY  "));
          break;
        case 3:  strcpy(timePhrase, PSTR("   TAG DER DEUTSCHEN EINHEIT    ")); // https://en.wikipedia.org/wiki/German_Unity_Day
          break;
        case 9:  strcpy(timePhrase, PSTR("     HAPPY LEIF ERIKSON DAY     "));
          break;
        case 10: strcpy(timePhrase, PSTR("      IT IS MORRISSEY DAY       ")); // also https://en.wikipedia.org/wiki/National_Day_of_the_Republic_of_China
          break;
        case 11: strcpy(timePhrase, PSTR(" HAPPY INDIGENOUS PEOPLES' DAY  "));
          break;
        case 12: strcpy(timePhrase, PSTR("      IT IS COLUMBUS DAY        "));
          break;
        case 13: strcpy(timePhrase, PSTR("       HAPPY NO BRA DAY         "));
          break;
        case 14: strcpy(timePhrase, PSTR("    HAPPY WORLD STANDARDS DAY   "));
          break;
        case 15: strcpy(timePhrase, PSTR(" FRIEDRICH NIETZSCHE'S BIRTHDAY ")); // also Fela Anikulapo Kuti's birthday
          break;
        case 21: strcpy(timePhrase, PSTR("        IT IS APPLE DAY         "));
          break;
        case 23: strcpy(timePhrase, PSTR("         HAPPY MOLE DAY         ")); // Celebrated annually on October 23 from 6:02 a.m. to 6:02 p.m., Mole Day commemorates Avogadro's Number (6.02 x 10²³)
          break;
        case 24: strcpy(timePhrase, PSTR("    IT IS UNITED NATIONS DAY    "));
          break;
        case 25: strcpy(timePhrase, PSTR("  HAPPY BIRTHDAY PABLO PICASSO  ")); // also Retrocession Day
          break;
        case 26: strcpy(timePhrase, PSTR("  IT IS INTERSEX AWARENESS DAY  "));
          break;
        case 28: strcpy(timePhrase, PSTR(" IT IS NATIONAL IMMIGRANTS DAY  "));
          break;
        case 29: strcpy(timePhrase, PSTR("1969 FIRST ARPANET MESSAGE SENT ")); // https://phrasee.co/news/a-brief-history-of-email/
          break;
        case 30: strcpy(timePhrase, PSTR("      IT IS DEVIL'S NIGHT       ")); // also Aboriginal Murador new year
          break;
        case 31: strcpy(timePhrase, PSTR("        HAPPY HALLOWEEN         "));
          break;
        default:  // if no special day, just show the time
          genTimePhrase(theHour, theMin);
          break;
      }
      break;
    case 11: // November
      switch (theDay) {
        case 1:  strcpy(timePhrase, PSTR("      FELIZ DIA DE MUERTOS      "));
          break;
        case 2:  strcpy(timePhrase, PSTR("      IT IS ALL SOULS' DAY      "));
          break;
        case 4:  strcpy(timePhrase, PSTR("IT IS YITZHAK RABIN MEMORIAL DAY"));
          break;
        case 5:  strcpy(timePhrase, PSTR("REMEMBER REMEMBER THE 5TH OF NOV")); // Guy Fawkes Day
          break;
        case 6:  strcpy(timePhrase, PSTR("     GLAD GUSTAV ADOLFSDAGEN    ")); // Gustavus Adolphus Day
          break;
        case 7:  strcpy(timePhrase, PSTR(" IT IS OCTOBER REVOLUTION DAY   "));
          break;
        case 9:  strcpy(timePhrase, PSTR("THE BERLIN WALL FELL ON THIS DAY")); // World Freedom Day - also Wu-Tang Clan Day
          break;
        case 10: strcpy(timePhrase, PSTR("    HEUTE IST MARTINISINGEN     "));
          break;
        case 11: strcpy(timePhrase, PSTR("      HAPPY ARMISTICE DAY       "));
          break;
        case 12: strcpy(timePhrase, PSTR("  HAPPY BIRTHDAY SUN YAT-SEN    "));
          break;
        case 13: strcpy(timePhrase, PSTR("LET'S DANCE    SADIE HAWKINS DAY"));
          break;
        case 15: strcpy(timePhrase, PSTR("  HAPPY OL' DIRTY BASTARD DAY   ")); // also Day of the Imprisoned Writer
          break;
        case 16: strcpy(timePhrase, PSTR("ARECIBO MESSAGE SENT TODAY 1974 "));
          break;
        case 17: strcpy(timePhrase, PSTR("SUEZ CANAL OPENED TODAY IN 1869 ")); // also Nixon said "I am not a crook" in 1973
          break;
        case 18: strcpy(timePhrase, PSTR("JONESTOWN MASSACRE TODAY IN 1978"));
          break;
        case 19: strcpy(timePhrase, PSTR("GETTYSBURG ADDRESS GIVEN IN 1863"));
          break;
        case 20: strcpy(timePhrase, PSTR(" TRANSGENDER DAY OF REMEMBRANCE ")); // also Nuremburg trials begin
          break;
        case 21: strcpy(timePhrase, PSTR("      HAPPY BIRTHDAY BJORK      ")); // also arpanet invented in 1969
          break;
        case 22: strcpy(timePhrase, PSTR("JFK WAS ASSASSINATED ON THIS DAY"));
          break;
        case 23: strcpy(timePhrase, PSTR("  HAPPY BIRTHDAY EL LISSITZKY   "));
          break;
        case 24: strcpy(timePhrase, PSTR("      HAPPY EVOLUTION DAY       "));
          break;
        case 25: strcpy(timePhrase, PSTR("ELIAN GONZALEZ WAS FOUND AT SEA "));
          break;
        case 26: strcpy(timePhrase, PSTR(" HAPPY BIRTHDAY EUGENE IONESCO  "));
          break;
        case 27: strcpy(timePhrase, PSTR("    HAPPY BIRTHDAY BRUCE LEE    "));
          break;
        case 28: strcpy(timePhrase, PSTR("IT IS THE START OF NATIVITY FAST"));
          break;
        case 29: strcpy(timePhrase, PSTR("HAPPY BIRTHDAY LOUISA MAY ALCOTT"));
          break;
        case 30: strcpy(timePhrase, PSTR("    HAPPY SAINT ANDREW'S DAY    "));
          break;
        default:  // if no special day, just show the time
          genTimePhrase(theHour, theMin);
          break;
      }
      break;
    case 12: // December
      switch (theDay) {
        case 1:  strcpy(timePhrase, PSTR("      IT IS WORLD AIDS DAY      "));
          break;
        case 2:  strcpy(timePhrase, PSTR("NAPOLEAN CROWNED HIMSELF EMPEROR"));
          break;
        case 3:  strcpy(timePhrase, PSTR("   IT IS BHOPAL DISASTER DAY    "));
          break;
        case 4:  strcpy(timePhrase, PSTR("HAPPY BIRTHDAY CHIEF CRAZY HORSE"));
          break;
        case 5:  strcpy(timePhrase, PSTR("      GRUSS VOM KRAMPUS         ")); // also Repeal Day
          break;
        case 7:  strcpy(timePhrase, PSTR("A DATE THAT WILL LIVE IN INFAMY "));
          break;
        case 8:  strcpy(timePhrase, PSTR("       HAPPY BODHI DAY          "));
          break;
        case 9:  strcpy(timePhrase, PSTR("   HAPPY BIRTHDAY JOHN MILTON   "));
          break;
        case 10: strcpy(timePhrase, PSTR("    HAPPY HUMAN RIGHTS DAY      "));
          break;
        case 11: strcpy(timePhrase, PSTR(" HAPPY BDAY FIORELLO LA GUARDIA "));
          break;
        case 12: strcpy(timePhrase, PSTR("  HAPPY BIRTHDAY FRANK SINATRA  "));
          break;
        case 13: strcpy(timePhrase, PSTR(" NANKING MASSACRE MEMORIAL DAY  "));
          break;
        case 14: strcpy(timePhrase, PSTR("        HAPPY MONKEY DAY        "));
          break;
        case 15: strcpy(timePhrase, PSTR("    HAPPY BILL OF RIGHTS DAY    ")); // https://en.wikipedia.org/wiki/United_States_Bill_of_Rights#Display_and_honoring_of_the_Bill_of_Rights
          break;
        case 16: strcpy(timePhrase, PSTR("  HAPPY BIRTHDAY PHILIP K DICK  "));
          break;
        case 17: strcpy(timePhrase, PSTR("        IO SATURNALIA           "));
          break;
        case 18: strcpy(timePhrase, PSTR("IT'S INTERNATIONAL MIGRANTS DAY ")); // https://en.wikipedia.org/wiki/International_Migrants_Day
          break;
        case 19: strcpy(timePhrase, PSTR("    HAPPY GOA LIBERATION DAY    ")); // https://en.wikipedia.org/wiki/Goa_Liberation_Day
          break;
        case 20: strcpy(timePhrase, PSTR("       HAPPY FOREFEAST          ")); // also first website created
          break;
        case 21: strcpy(timePhrase, PSTR("     MERRY WINTER SOLSTICE      "));
          break;
        case 23: strcpy(timePhrase, PSTR("IT'S FESTIVUS FOR THE REST OF US"));
          break;
        case 24: strcpy(timePhrase, PSTR("     MERRY CHRISTMAS EVE        "));
          break;
        case 25: strcpy(timePhrase, PSTR("        MERRY CHRISTMAS         "));
          break;
        case 26: strcpy(timePhrase, PSTR("        HAPPY BOXING DAY        ")); // 1st day of Kwanzaa
          break;
        case 31: strcpy(timePhrase, PSTR("      HAPPY NEW YEAR'S EVE      "));
          break;
        default:  // if no special day, just show the time
          genTimePhrase(theHour, theMin);
          break;
      }
      break;
    default:  // if no special month, just show the time
      genTimePhrase(theHour, theMin);
      break;
  }
}
