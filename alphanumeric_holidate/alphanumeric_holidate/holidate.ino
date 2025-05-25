

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
          break;
        case 2:  strcpy(timePhrase, PSTR("        HAPPY NYINLONG          "));
          break;
        case 3:  strcpy(timePhrase, PSTR("  HAPPY BIRTHDAY ANNA MAY WONG  "));
          break;
        case 4:  strcpy(timePhrase, PSTR("HAPPY BIRTHDAY SIR ISAAC NEWTON ")); // also Burma Independence Day
          break;
        case 5:  strcpy(timePhrase, PSTR("       HAPPY EPIPHANY EVE       ")); // also Joma Shinji
          break;
        case 6:  strcpy(timePhrase, PSTR("       FELIZ DIA DE REYES       "));
          break;
        case 7:  strcpy(timePhrase, PSTR("        KALA CHRISTOUGENA       "));
          break;
        case 8:  strcpy(timePhrase, PSTR("   HAPPY BIRTHDAY DAVID BOWIE   ")); // also Elvis Presley
          break;
        case 9:  strcpy(timePhrase, PSTR("       FELIX DIES AGONALIS      ")); // https://en.wikipedia.org/wiki/Agonalia
          break;
        case 10: strcpy(timePhrase, PSTR("CAESAR CROSSES THE RUBICON 49 BC")); // https://en.wikipedia.org/wiki/Rubicon
          break;
        case 11: strcpy(timePhrase, PSTR("        FELIX CARMENTALIA       ")); // https://en.wikipedia.org/wiki/Carmentalia or https://en.wikipedia.org/wiki/Juturna
          break;
        case 12: strcpy(timePhrase, PSTR("YENNAYER   START OF AMAZIGH YEAR")); // https://en.wikipedia.org/wiki/Yennayer
          break;
        case 13: strcpy(timePhrase, PSTR("    HAPPY OLD NEW YEAR'S EVE    "));
          break;
        case 14: strcpy(timePhrase, PSTR("      HAPPY OLD NEW YEAR        ")); // orthodox new year https://en.wikipedia.org/wiki/Old_New_Year
          break;
        case 15: strcpy(timePhrase, PSTR("   IT IS NATIONAL NOTHING DAY   ")); //also https://en.wikipedia.org/wiki/Carmentalia
          break;
        case 16: strcpy(timePhrase, PSTR("MARTIN LUTHER KING JR'S BIRTHDAY"));
          break;
        case 17: strcpy(timePhrase, PSTR(" HAPPY START OF PATRAS CARNIVAL ")); // https://en.wikipedia.org/wiki/Patras_Carnival - also Ben Franklin / Muhammad Ali / Ryuichi Sakamoto's birthday - also date Prohibition started
          break;
        case 18: strcpy(timePhrase, PSTR("   HAPPY BIRTHDAY CARY GRANT    "));
          break;
        case 19: strcpy(timePhrase, PSTR("          HAPPY TIMKAT          ")); //https://en.wikipedia.org/wiki/Timkat
          break;
        case 20: strcpy(timePhrase, PSTR("     IT IS INAUGURATION DAY     ")); // check year? (y % 4 == 1)but we gotta pass that through...
          break;
        case 21: strcpy(timePhrase, PSTR("   BONNE FETE DES FLEURDELISE   ")); // https://en.wikipedia.org/wiki/Flag_of_Quebec
          break;
        case 22: strcpy(timePhrase, PSTR("  HAPPY UKRAINIAN DAY OF UNITY  ")); // https://en.wikipedia.org/wiki/Day_of_Unity_of_Ukraine also Sam Cooke's birthday
          break;
        case 23: strcpy(timePhrase, PSTR("       WORLD FREEDOM DAY        ")); // https://en.wikipedia.org/wiki/World_League_for_Freedom_and_Democracy#World_Freedom_Day
          break;
        case 24: strcpy(timePhrase, PSTR("    FELIX FERIAE SEMENTIVAE     ")); // https://en.wikipedia.org/wiki/Sementivae - also Jolly Belly Laigh Day "JOLLY BELLY LAUGH DAY   HA HA HA"
          break;
        case 25: strcpy(timePhrase, PSTR("SLAINTE MHATH   IT'S BURNS NIGHT")); // Sláinte Mhath - Oidhche Bhlas Burns
          break;
        case 26: strcpy(timePhrase, PSTR("      IT IS AUSTRAILIA DAY      ")); // https://en.wikipedia.org/wiki/Australia_Day
          break;
        case 27: strcpy(timePhrase, PSTR("IT IS HOLOCAUST REMEMBRANCE DAY "));
          break;
        case 28: strcpy(timePhrase, PSTR("     IT IS DATA PRIVACY DAY     "));
          break;
        case 29: strcpy(timePhrase, PSTR("        IT IS KANSAS DAY        ")); // https://en.wikipedia.org/wiki/Kansas_Day
          break;
        case 30: strcpy(timePhrase, PSTR("    IT IS FRED KOREMATSU DAY    ")); // also   // Feliz dia da saudade
          break;
        case 31: strcpy(timePhrase, PSTR("BREXIT DAY    UK LEFT EU IN 2020")); // also Jackie Robinson / Alan Lomax's birthday
          break;
        default:  // if no special day, just show the time
          genTimePhrase(theHour, theMin);
          break;
      }
      break;
    case 2: // February
      switch (theDay) {
        case 1:  strcpy(timePhrase, PSTR("         HAPPY IMBOLC           ")); // also Candlemas
          break;
        case 2:  strcpy(timePhrase, PSTR("      HAPPY GROUNDHOG DAY       "));
          break;
        case 3:  strcpy(timePhrase, PSTR(" THROW SOME BEANS FOR SETSUBUN  ")); // https://en.wikipedia.org/wiki/Setsubun Oni wa soto! Fuku wa uchi!
          break;
        case 4:  strcpy(timePhrase, PSTR("      HAPPY ROSA PARKS DAY      "));
          break;
        case 5:  strcpy(timePhrase, PSTR("     KASHMIR SOLIDARITY DAY     ")); // https://en.wikipedia.org/wiki/Kashmir_Solidarity_Day
          break;
        case 6:  strcpy(timePhrase, PSTR("IT IS ZERO TOLERANCE FOR FGM DAY")); // https://en.wikipedia.org/wiki/International_Day_of_Zero_Tolerance_for_Female_Genital_Mutilation
          break; // also Waitangi Day
        case 7:  strcpy(timePhrase, PSTR(" HAPPY GRENADA INDEPENDENCE DAY ")); // https://en.wikipedia.org/wiki/Independence_Day_(Grenada)
          break;
        case 8:  strcpy(timePhrase, PSTR("      HAPPY NIRVANA DAY         ")); // Mahayana, most celebrate on the 15th
          break;
        case 9:  strcpy(timePhrase, PSTR("BEATLES PERFORMED ON ED SULLIVAN")); //
          break;
        case 10: strcpy(timePhrase, PSTR("  FEAST OF ST PAUL'S SHIPWRECK  ")); // https://en.wikipedia.org/wiki/Public_holidays_in_Malta#February
          break;
        case 11: strcpy(timePhrase, PSTR(" IRANIAN REVOLUTION WAS IN 1979 ")); // also https://en.wikipedia.org/wiki/National_Foundation_Day_(Japan) and Inventor's Day
          break; 
        case 12: strcpy(timePhrase, PSTR("       HAPPY DARWIN DAY         "));  // also Lincoln's Birthday
          break;
        case 13: strcpy(timePhrase, PSTR("       FELIX PARENTAILIA        ")); // https://en.wikipedia.org/wiki/Parentalia
          break;
        case 14: strcpy(timePhrase, PSTR("     HAPPY VALENTINE'S DAY      "));
          break;
        case 15: strcpy(timePhrase, PSTR("       FELIX LUPERCALIA         ")); // also Single's Awareness Day
          break;
        case 16: strcpy(timePhrase, PSTR("LITHUANIAN STATEHOOD RESTORATION")); // https://en.wikipedia.org/w/index.php?title=Statehood_Restoration_Day
          break;
        case 17: strcpy(timePhrase, PSTR("       FELIX QUIRINALIA         ")); // https://en.wikipedia.org/wiki/Quirinus#Festivals
          break;
        case 18: strcpy(timePhrase, PSTR("    GAMBIAN INDEPENDENCE DAY    ")); // https://en.wikipedia.org/wiki/Independence_Day_(Gambia)
          break;
        case 19: strcpy(timePhrase, PSTR("DAY OF REMEMBRANCE EX ORDER 9066"));
          break;
        case 20: strcpy(timePhrase, PSTR("   HAPPY BIRTHDAY KURT COBAIN   "));
          break;
        case 21: strcpy(timePhrase, PSTR("         FELIX FERALIA          ")); // also Nina Simone's birthday - Malcolm X assassination
          break;
        case 22: strcpy(timePhrase, PSTR(" GEORGE WASHINGTON'S BIRTHDAY   ")); // also https://en.wikipedia.org/wiki/Caristia
          break;
        case 23: strcpy(timePhrase, PSTR("        FELIX TERMINALIA        ")); // https://en.wikipedia.org/wiki/Terminalia_(festival) also Malevich and Emperor Naruhito's birthday
          break;
        case 24: strcpy(timePhrase, PSTR("        FELIX REGIFUGIUM        ")); // https://en.wikipedia.org/wiki/Regifugium also Dragobetele saruta fetele
          break;
        case 25: strcpy(timePhrase, PSTR("      KUWAITI NATIONAL DAY      ")); // https://en.wikipedia.org/wiki/National_Day_(Kuwait)
          break;
        case 26: strcpy(timePhrase, PSTR("   HAPPY BIRTHDAY JOHNNY CASH   "));
          break;
        case 27: strcpy(timePhrase, PSTR("         FELIX EQUIRRIA         ")); // https://en.wikipedia.org/wiki/Equirria also Polar Bear Day
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
        case 1:  strcpy(timePhrase, PSTR("        FELIX MATRONALIA        ")); // https://en.wikipedia.org/wiki/Matronalia
          break;
        case 2:  strcpy(timePhrase, PSTR("     HAPPY ADWA VICTORY DAY     ")); // https://en.wikipedia.org/wiki/Adwa_Victory_Day
          break;
        case 3:  strcpy(timePhrase, PSTR("  HAPPY BIRTHDAY GEORG CANTOR   "));
          break;
        case 4:  strcpy(timePhrase, PSTR("KAZIUKO MUGE   ST CASIMIR'S FAIR")); // https://en.wikipedia.org/wiki/Kaziuko_mug%C4%97
          break;
        case 5:  strcpy(timePhrase, PSTR(" IT IS LEARN FROM LEI FENG DAY  "));
          break;
        case 6:  strcpy(timePhrase, PSTR("     GHANA INDEPENDENCE DAY     ")); // https://en.wikipedia.org/wiki/Independence_Day_(Ghana)
          break;
        case 7:  strcpy(timePhrase, PSTR("         FELIX VEDIOVIS         "));
          break;
        case 8:  strcpy(timePhrase, PSTR("HAPPY INTERNATIONAL WOMEN'S DAY "));
          break;
        case 9:  strcpy(timePhrase, PSTR("HAPPY BIRTHDAY AMERIGO VESPUCCI "));
          break;
        case 10: strcpy(timePhrase, PSTR("    HAPPY HARRIET TUBMAN DAY    ")); // also https://en.wikipedia.org/wiki/Tibetan_Uprising_Day
          break;
        case 11: strcpy(timePhrase, PSTR("LITHUANIAN INDEPENDENCE RESTORED")); // https://en.wikipedia.org/wiki/Public_holidays_in_Lithuania
          break;
        case 12: strcpy(timePhrase, PSTR("     FELIZ ANO NUEVO AZTECA     "));
          break;
        case 13: strcpy(timePhrase, PSTR("      HAPPY CHANG THAI DAY      ")); // https://en.wikipedia.org/wiki/National_Elephant_Day_(Thailand)
          break;
        case 14:
          if (theHour == 13 && theMin == 59) { // 1:59 PM
            strcpy(timePhrase, PSTR("        HAPPY PI MINUTE         "));
          } else {
            strcpy(timePhrase, PSTR("          HAPPY PI DAY          ")); // also Einstein's birthday - also https://en.wikipedia.org/wiki/Equirria
          }
          break;
        case 15: strcpy(timePhrase, PSTR("    BEWARE THE IDES OF MARCH    "));
          break;
        case 16: strcpy(timePhrase, PSTR("    PROCESSION OF THE ARGEI     ")); // https://en.wikipedia.org/wiki/Argei
          break;
        case 17: strcpy(timePhrase, PSTR("        ERIN GO BRAGH           ")); // also Liberalia https://en.wikipedia.org/wiki/Liberalia
          break;
        case 18: strcpy(timePhrase, PSTR("      HAPPY SHEELAH'S DAY       ")); // https://en.wikipedia.org/wiki/Sheelah%27s_Day
          break;
        //case 19: strcpy(timePhrase, PSTR("      FELIX QUINQUATRIA         ")); // https://en.wikipedia.org/wiki/Quinquatria
        //  break;
        case 19: strcpy(timePhrase, PSTR("     MERRY VERNAL EQUINOX       ")); // can move a bit
          break;
        case 20: strcpy(timePhrase, PSTR("  FEAST OF THE SUPREME RITUAL   ")); // https://en.wikipedia.org/wiki/Thelema#Holidays
          break;
        //case 21: strcpy(timePhrase, PSTR("         NOWRUZ MOBARAK         ")); // can move a bit
        //  break;
        case 21: strcpy(timePhrase, PSTR("ALCATRAZ CLOSED THIS DAY IN 1963")); //
          break;
        case 22: strcpy(timePhrase, PSTR(" DIA DE ABOLICION DE ESCLAVITUD ")); // https://en.wikipedia.org/wiki/Emancipation_Day#Puerto_Rico_%E2%80%93_March_22
          break;
        case 23: strcpy(timePhrase, PSTR("    IT IS YAUM-E-MASIH MAUD     ")); // https://en.wikipedia.org/wiki/Promised_Messiah_Day also https://en.wikipedia.org/wiki/Tubilustrium
          break;
        case 24: strcpy(timePhrase, PSTR("   REMEMBER TRUTH AND JUSTICE   ")); // https://en.wikipedia.org/wiki/Day_of_Remembrance_for_Truth_and_Justice
          break;
        case 25: strcpy(timePhrase, PSTR("REMEMBRANCE DAY SLAVERY VICTIMS ")); // https://en.wikipedia.org/wiki/International_Day_of_Remembrance_of_the_Victims_of_Slavery_and_the_Transatlantic_Slave_Trade
          break;
        case 26: strcpy(timePhrase, PSTR("   HAPPY FREE THE NIPPLE DAY    ")); // https://www.internationaldays.co/event/free-the-nipple-day/r/rece4NpmCWxkVnBnx
          break;
        case 27: strcpy(timePhrase, PSTR("HAPPY INTERNATIONAL WHISKEY DAY "));
          break;
        case 28: strcpy(timePhrase, PSTR("  FIRST SEAPLANE FLEW IN 1910   "));
          break;
        case 29: strcpy(timePhrase, PSTR("   HAPPY YOUTH DAY IN TAIWAN    ")); // https://en.wikipedia.org/wiki/Youth_Day#Taiwan
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
        case 2:  strcpy(timePhrase, PSTR("      DIA DE LAS MALVINAS       ")); // https://en.wikipedia.org/wiki/Malvinas_Day
          break;
        case 3:  strcpy(timePhrase, PSTR("FIRST FLIGHT OVER MOUNT EVEREST ")); // https://en.wikipedia.org/wiki/Houston%E2%80%93Mount_Everest_flight_expedition
          break;
        case 4:  strcpy(timePhrase, PSTR("        FELIX MEGALESIA         ")); // also MLK Jr. assassination
          break;
        case 5:  strcpy(timePhrase, PSTR("     HAPPY COLD FOOD FESTIVAL   "));
          break;
        case 6:  strcpy(timePhrase, PSTR("         HAPPY TARTAN DAY       ")); // New Beer's Eve
          break;
        case 7:  strcpy(timePhrase, PSTR(" HAPPY BIRTHDAY BILLIE HOLIDAY  "));
          break;
        case 8:  strcpy(timePhrase, PSTR("    INTERNATIONAL ROMANI DAY    ")); // https://en.wikipedia.org/wiki/International_Romani_Day
          break;
        case 9:  strcpy(timePhrase, PSTR("ARAW NG KAGLITINGAN   BATAAN DAY")); // https://en.wikipedia.org/wiki/Day_of_Valor
          break;
        case 10: strcpy(timePhrase, PSTR(" TITANTIC MAIDEN VOYAGE IN 1912 ")); //
          break;
        case 11: strcpy(timePhrase, PSTR("NAPOLEON ABDICATED THIS DAY 1814")); //
          break;
        case 12: strcpy(timePhrase, PSTR("       HAPPY YURI'S NIGHT       ")); // also Cerialia https://en.wikipedia.org/wiki/Cerealia
          break;
        case 13: strcpy(timePhrase, PSTR("         HAPPY SONGKRAN         ")); // also https://en.wikipedia.org/wiki/Vaisakhi - also Thomas Jefferson's birthday
          break;
        case 14: strcpy(timePhrase, PSTR("EAT JAJANGMYEON   IT'S BLACK DAY")); // https://en.wikipedia.org/wiki/Black_Day_(South_Korea)
          break;                                                               // also https://en.wikipedia.org/wiki/Puthandu Tamil New Year // also Lincoln assassination
        case 15: strcpy(timePhrase, PSTR("          HAPPY TAX DAY         ")); // also Fordicidia https://en.wikipedia.org/wiki/Fordicidia
          break;
        case 16: strcpy(timePhrase, PSTR("HOFFMAN SYNTHESIZED LSD IN 1938 ")); // https://en.wikipedia.org/wiki/History_of_LSD
          break;
        case 17: strcpy(timePhrase, PSTR("      SYRIAN EVACUATION DAY     ")); // https://en.wikipedia.org/wiki/Evacuation_Day_(Syria)
          break;
        case 18: strcpy(timePhrase, PSTR("   ZIMBABWEAN INDEPENDENCE DAY  ")); // https://en.wikipedia.org/wiki/Independence_Day_(Zimbabwe)
          break;
        case 19: strcpy(timePhrase, PSTR("        HAPPY BICYCLE DAY       ")); // https://en.wikipedia.org/wiki/History_of_lysergic_acid_diethylamide#%22Bicycle_Day%22
          break;
        case 20: strcpy(timePhrase, PSTR("           HAPPY 4/20           "));
          break;
        case 21: strcpy(timePhrase, PSTR("ABU YE      HAPPY GROUNATION DAY")); // https://en.wikipedia.org/wiki/Grounation_Day
          break;
        case 22: strcpy(timePhrase, PSTR("        HAPPY EARTH DAY         "));
          break;
        case 23: strcpy(timePhrase, PSTR("      FELIX VINALIA URBANA      ")); // https://en.wikipedia.org/wiki/Vinalia - also Feast of St. George
          break;
        case 24: strcpy(timePhrase, PSTR(" ARMENIAN GENOCIDE MEMORIAL DAY ")); // https://en.wikipedia.org/wiki/Armenian_Genocide_Remembrance_Day
          break;
        case 25: strcpy(timePhrase, PSTR("         HAPPY DNA DAY          ")); // also https://en.wikipedia.org/wiki/Robigalia
          break;
        case 26: strcpy(timePhrase, PSTR("  IT IS CHERNOBYL DISASTER DAY  ")); //  International Chernobyl Disaster Remembrance Day
          break;
        case 27: strcpy(timePhrase, PSTR("     GELUKKIGE VRYHEIDSDAG      ")); // Freedom Day South Africa
          break;
        case 28: strcpy(timePhrase, PSTR("     SA DIE DE SA SARDIGNA      ")); // https://en.wikipedia.org/wiki/Sa_die_de_sa_Sardigna - also Tristan Tzara's birthday - or https://en.wikipedia.org/wiki/Floralia
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
        case 2:  strcpy(timePhrase, PSTR(" INTERNATIONAL HARRY POTTER DAY "));
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
        case 10: strcpy(timePhrase, PSTR("   ROMANIAN INDEPENDENCE DAY    "));
          break;
        case 11: strcpy(timePhrase, PSTR("  HAPPY BIRTHDAY SALVADOR DALI  "));
          break;
        case 12: strcpy(timePhrase, PSTR("  HAPPY NATIONAL LIMERICK DAY   ")); // https://www.awarenessdays.com/awareness-days-calendar/national-limerick-day-2023/
          break;
        case 13: strcpy(timePhrase, PSTR("1ST RADIO BROADCAST MADE IN 1897")); // https://www.bbc.com/news/uk-england-somerset-61327062
          break;
        case 14: strcpy(timePhrase, PSTR("  PARAGUAYAN INDEPENDENCE DAY   ")); // https://en.wikipedia.org/wiki/Independence_Day_(Paraguay)
          break;
        case 15: strcpy(timePhrase, PSTR("        IT IS NAKBA DAY         ")); // also Brian Eno's birthday
          break;
        case 16: strcpy(timePhrase, PSTR("   CHARTREUSE DAY SINCE 1605    ")); //
          break;
        case 17: strcpy(timePhrase, PSTR("    HAPPY BIRTHDAY ERIK SATIE   "));
          break;
        case 18: strcpy(timePhrase, PSTR("BATTLE OF MONTE CASSINO IN 1944 ")); // https://en.wikipedia.org/wiki/Battle_of_Monte_Cassino
          break;
        case 19: strcpy(timePhrase, PSTR("      HAPPY MALCOLM X DAY       ")); // https://en.wikipedia.org/wiki/Malcolm_X_Day
          break;
        case 20: strcpy(timePhrase, PSTR(" DAY OF REMEMBRANCE IN CAMBODIA "));
          break;
        case 21: strcpy(timePhrase, PSTR("  DIA DE LA AFROCOLOMBIANIDAD   "));
          break;
        case 22: strcpy(timePhrase, PSTR("     IT IS HARVEY MILK DAY      ")); // also Al-Quds Day - also Sun Ra's birthday
          break;
        case 23: strcpy(timePhrase, PSTR("       FELIX TUBILUSTRIUM       ")); // https://en.wikipedia.org/wiki/Tubilustrium
          break;
        case 24: strcpy(timePhrase, PSTR(" HAPPY BROOKLYN BRIDGE BIRTHDAY ")); // also https://en.wikipedia.org/wiki/Independence_Day_(Eritrea)
          break;
        case 25: strcpy(timePhrase, PSTR("        HAPPY AFRICA DAY        "));
          break;
        case 26: strcpy(timePhrase, PSTR("   HAPPY BIRTHDAY MILES DAVIS   "));
          break;
        case 27: strcpy(timePhrase, PSTR("HAPPY BIRTHDAY CHRYSLER BUILDING"));
          break;
        case 28: strcpy(timePhrase, PSTR("     ARMENIAN REPUBLIC DAY      ")); // https://en.wikipedia.org/wiki/Republic_Day_(Armenia)
          break;
        //case 28: strcpy(timePhrase, s_manhattanhenge);
        //  break;
        case 29: strcpy(timePhrase, PSTR("       HAPPY OAK APPLE DAY      "));
          break;
        case 30: strcpy(timePhrase, PSTR(" HAPPY BIRTHDAY MIKHAIL BAKUNIN ")); // also https://en.wikipedia.org/wiki/Statehood_Day_(Croatia)
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
        case 1:  strcpy(timePhrase, PSTR("     SAMOAN INDEPENDENCE DAY    ")); // https://en.wikipedia.org/wiki/Independence_Day_(Samoa)
          break;
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
        case 7:  strcpy(timePhrase, PSTR("        FELIX VESTALIA          ")); // https://en.wikipedia.org/wiki/Vestalia
          break;
        case 8:  strcpy(timePhrase, PSTR("     HAPPY WORLD OCEANS DAY     ")); // https://worldoceanday.org/
          break;
        case 9:  strcpy(timePhrase, PSTR("        DIA DE LA RIOJA         ")); //
          break;
        case 10: strcpy(timePhrase, PSTR("     FELIZ DIA DE PORTUGAL      "));
          break;
        case 11: strcpy(timePhrase, PSTR("  HAPPY KING KAMEHAMEHA I DAY   "));
          break;
        case 12: strcpy(timePhrase, PSTR("        HAPPY LOVING DAY        "));
          break;
        case 13: strcpy(timePhrase, PSTR("  HAPPY QUINQUATRUS MINUSCULAE  "));
          break;
        case 14: strcpy(timePhrase, PSTR("        HAPPY FLAG DAY          "));
          break;
        case 15: strcpy(timePhrase, PSTR("FELIX QUANDO STERCUM DELATUM FAS")); // https://en.wikipedia.org/wiki/Vestalia
          break;
        case 16: strcpy(timePhrase, PSTR("        HAPPY BLOOMSDAY         "));
          break;
        case 17: strcpy(timePhrase, PSTR("     ICELAND NATIONAL DAY       "));
          break;
        case 18: strcpy(timePhrase, PSTR("      HAPPY WATERLOO DAY        "));
          break;
        case 19: strcpy(timePhrase, PSTR("       HAPPY JUNETEENTH         "));
          break;
        case 20: strcpy(timePhrase, PSTR("     HAPPY SUMMER SOLSTICE      ")); // can move a bit
          break;
        case 21: strcpy(timePhrase, PSTR("     HAPPY MAKE MUSIC DAY       "));
          break;
        case 22: strcpy(timePhrase, PSTR("       IT IS WINDRUSH DAY       "));
          break;
        case 23: strcpy(timePhrase, PSTR("   HAPPY BIRTHDAY ALAN TURING   ")); // https://en.wikipedia.org/wiki/Alan_Turing
          break;
        case 24: strcpy(timePhrase, PSTR("      HAPPY MIDSUMMER DAY       ")); // St John's Day
          break;
        case 25: strcpy(timePhrase, PSTR("   HAPPY ANTHONY BOURDAIN DAY   ")); // also George Orwell's birthday
          break;
        case 26: strcpy(timePhrase, PSTR("    HAPPY RATCATCHER'S DAY      ")); // https://en.wikipedia.org/wiki/Ratcatcher%27s_Day
          break;
        case 27: strcpy(timePhrase, PSTR("    HAPPY HELEN KELLER DAY      ")); // also Emma Goldman's birthday
          break;
        case 28: strcpy(timePhrase, PSTR(" HAPPY STONEWALL LIBERATION DAY ")); // Christopher Street Day - also Franz Ferdinand assassinated
          break;
        case 29: strcpy(timePhrase, PSTR("  SEYCHELLES INDEPENDENCE DAY   ")); // https://en.wikipedia.org/wiki/Independence_Day_(Seychelles)
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
        case 3:  strcpy(timePhrase, PSTR("  BELARUSIAN INDEPENDENCE DAY   ")); // https://en.wikipedia.org/wiki/Independence_Day_(Belarus)
          break;
        case 4:  strcpy(timePhrase, PSTR("     HAPPY INDEPENDENCE DAY     "));
          break;
        case 5:  strcpy(timePhrase, PSTR("        FELIX POPLIFUGIA        ")); // https://en.wikipedia.org/wiki/Poplifugia also Bikini Day
          break;
        case 6:  strcpy(timePhrase, PSTR("     FELIX LUDI APOLLINARES     ")); // https://en.wikipedia.org/wiki/Ludi_Apollinares
          break;
        case 7:  strcpy(timePhrase, PSTR("       HAPPY QIXI FESTIVAL      "));
          break;
        case 8:  strcpy(timePhrase, PSTR("         FELIX VITULATIO        ")); // https://en.wikipedia.org/wiki/Vitulatio
          break;
        case 9:  strcpy(timePhrase, PSTR("   ARGENTINA INDEPENDENCE DAY   ")); // https://en.wikipedia.org/wiki/Argentina_Independence_Day
          break;
        case 10: strcpy(timePhrase, PSTR("     HAPPY NIKOLA TESLA DAY     "));
          break;
        case 11: strcpy(timePhrase, PSTR("   IT IS WORLD POPULATION DAY   "));
          break;
        case 12: strcpy(timePhrase, PSTR("   KIRIBATI INDEPENDENCE DAY    "));
          break;
        case 13: strcpy(timePhrase, s_manhattanhenge);
          break;
        case 14: strcpy(timePhrase, PSTR("    JOYEUX QUATORZE JUILLET     ")); // Bastille Day
          break;
        case 15: strcpy(timePhrase, PSTR("   FELIX TRANSVECTIO EQUITUM    ")); // https://en.wikipedia.org/wiki/Transvectio_equitum
          break;
        case 16: strcpy(timePhrase, PSTR(" TRINITY TEST WAS TODAY IN 1945 ")); // https://en.wikipedia.org/wiki/Trinity_(nuclear_test)
          break;
        case 17: strcpy(timePhrase, PSTR("     HAPPY WORLD EMOJI DAY      "));
          break;
        case 18: strcpy(timePhrase, PSTR("    HAPPY NELSON MANDELA DAY    "));
          break;
        case 19: strcpy(timePhrase, PSTR("         FELIX LUCARIA          ")); // https://en.wikipedia.org/wiki/Lucaria
          break;
        case 20: strcpy(timePhrase, PSTR(" MOON LANDING WAS TODAY IN 1969 "));
          break;
        case 21: strcpy(timePhrase, PSTR("      BELGIAN NATIONAL DAY      ")); // https://en.wikipedia.org/wiki/National_Day_(Belgium)
          break;
        case 22: strcpy(timePhrase, PSTR("   HAPPY PI APPROXIMATION DAY   ")); // 22/7
          break;
        case 23: strcpy(timePhrase, PSTR("HAPPY BIRTHDAY HAILE SELASSIE I ")); // also https://en.wikipedia.org/wiki/Neptunalia
          break;
        case 24: strcpy(timePhrase, PSTR("  HAPPY BIRTHDAY SIMON BOLIVAR  ")); //
          break;
        case 25: strcpy(timePhrase, PSTR("       FELIX FURRINALIA         ")); // https://en.wikipedia.org/wiki/Furrinalia
          break;
        case 26: strcpy(timePhrase, PSTR("    FELICAN ESPERANTAN TAGON    ")); // felican esperantan tagon
          break;
        case 27: strcpy(timePhrase, PSTR("WAKE UP     IT'S SLEEPY HEAD DAY")); // https://en.wikipedia.org/wiki/National_Sleepy_Head_Day "KOREAN WAR ARMISTICE WAS IN 1953"
          break;
        case 28: strcpy(timePhrase, PSTR(" HAPPY BIRTHDAY MARCEL DUCHAMP  "));
          break;
        case 29: strcpy(timePhrase, PSTR("      HAPPY BIRTHDAY NASA       "));
          break;
        case 30: strcpy(timePhrase, PSTR("    VANUATU INDEPENDENCE DAY    ")); // https://en.wikipedia.org/wiki/Independence_Day_(Vanuatu)
          break;
        case 31: strcpy(timePhrase, PSTR("  RIP ANTOINE DE SAINT-EXUPERY  ")); // https://en.wikipedia.org/wiki/Antoine_de_Saint-Exup%C3%A9ry
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
        case 3:  strcpy(timePhrase, PSTR("HIDE YOUR DOGS   SUPPLICIA CANUM")); // https://en.wikipedia.org/wiki/Supplicia_canum
          break;
        case 4:  strcpy(timePhrase, PSTR("      HAPPY BARACK OBAMA DAY    "));
          break;
        case 5:  strcpy(timePhrase, PSTR(" BURKINA FASO INDEPENDENCE DAY  ")); // https://en.wikipedia.org/wiki/Independence_Day_(Burkina_Faso)
          break;
        case 6:  strcpy(timePhrase, PSTR("       IT IS HIROSHIMA DAY      ")); // also Andy Warhol's birthday
          break;
        case 8:  strcpy(timePhrase, PSTR("NEVER FORGET   THE 8888 UPRISING")); // Burma     also international Cat Day
          break;
        case 9:  strcpy(timePhrase, PSTR("        IT IS NAGASAKI DAY      "));
          break;
        case 10: strcpy(timePhrase, PSTR("  ECUADOREAN INDEPENDENCE DAY   ")); // https://en.wikipedia.org/wiki/Independence_Day_(Ecuador)
          break;
        case 11: strcpy(timePhrase, PSTR("     CHAD INDEPENDENCE DAY      ")); // https://en.wikipedia.org/wiki/Independence_Day_(Chad)
          break;
        case 12: strcpy(timePhrase, PSTR("FEAST OF THE PROPHET & HIS BRIDE")); // https://en.wikipedia.org/wiki/Thelema#Holidays
          break;
        case 13: strcpy(timePhrase, PSTR(" INTERNATIONAL LEFTHANDERS DAY  ")); // also https://en.wikipedia.org/wiki/Nemoralia
          break;
        case 14: strcpy(timePhrase, PSTR("HAPPY PAKISTANI INDEPENDENCE DAY")); // https://en.wikipedia.org/wiki/Independence_Day_(Pakistan)
          break;
        case 15: strcpy(timePhrase, PSTR(" HAPPY INDIAN INDEPENDENCE DAY  ")); // https://en.wikipedia.org/wiki/Independence_Day_(India)
          break;
        case 16: strcpy(timePhrase, PSTR("   DOMINICAN RESTORATION DAY    ")); // https://en.wikipedia.org/wiki/Restoration_Day_(Dominican_Republic)
          break;
        case 17: strcpy(timePhrase, PSTR("     HAPPY MARCUS GARVEY DAY    ")); // also https://en.wikipedia.org/wiki/Portunalia
          break;
        case 18: strcpy(timePhrase, PSTR(" HELIUM WAS DISCOVERED IN 1868  ")); // https://phys.org/news/2016-03-helium.html
          break;
        case 19: strcpy(timePhrase, PSTR("      FELIX VINALIA RUSTICA     ")); // https://en.wikipedia.org/wiki/Vinalia
          break;
        case 20: strcpy(timePhrase, PSTR(" VOYAGER 2 LAUNCHED TODAY 1977  ")); // https://en.wikipedia.org/wiki/Voyager_2
          break;
        case 21: strcpy(timePhrase, PSTR("        FELIX CONSUALIA         ")); // https://en.wikipedia.org/wiki/Consualia
          break;
        case 22: strcpy(timePhrase, PSTR("HAPPY BDAY HENRI CARTIER-BRESSON")); //
          break;
        case 23: strcpy(timePhrase, PSTR("        FELIX VULCANALIA        ")); // https://en.wikipedia.org/wiki/Vulcanalia
          break;
        case 24: strcpy(timePhrase, PSTR("  INDEPENDENCE DAY OF UKRAINE   ")); // https://en.wikipedia.org/wiki/Independence_Day_of_Ukraine
          break;
        case 25: strcpy(timePhrase, PSTR("        FELIX OPICONSIVIA       ")); // https://en.wikipedia.org/wiki/Opiconsivia
          break;
        case 27: strcpy(timePhrase, PSTR("        FELIX VOLTURNALIA       ")); // https://en.wikipedia.org/wiki/Volturnalia also Man Ray's birthday
          break;
        case 28: strcpy(timePhrase, PSTR("  MLK JR SAID 'I HAVE A DREAM'  ")); // also Goethe's birthday
          break;
        case 29: strcpy(timePhrase, PSTR(" SOVIETS GOT THE A-BOMB IN 1949 "));
          break;
        case 30: strcpy(timePhrase, PSTR("HURRICAN KATRINA STRUCK IN 2005 "));
          break;
        case 31: strcpy(timePhrase, PSTR("  REST IN PEACE PRINCESS DIANA  "));
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
        case 2:  strcpy(timePhrase, PSTR("    VIETNAM INDEPENDENCE DAY    ")); // https://en.wikipedia.org/wiki/Independence_Day_(Vietnam)
          break;
        case 3:  strcpy(timePhrase, PSTR("     QATAR INDEPENDENCE DAY     "));
          break;
        case 4:  strcpy(timePhrase, PSTR("  HAPPY BIRTHDAY RICHARD WRIGHT "));
          break;
        case 5:  strcpy(timePhrase, PSTR(" VOYAGER 1 LAUNCHED TODAY 1977  ")); // https://en.wikipedia.org/wiki/Voyager_1
          break;
        case 6:  strcpy(timePhrase, PSTR("           SOMHLOLO DAY         ")); // Eswatini Independence Day
          break;
        case 7:  strcpy(timePhrase, PSTR("         SETE DE SETEMBRO       ")); // https://en.wikipedia.org/wiki/Independence_Day_(Brazil)
          break;
        case 8:  strcpy(timePhrase, PSTR("        DEN NA NEZAVISNOSTA     ")); // https://en.wikipedia.org/wiki/Independence_Day_(North_Macedonia)
          break;
        case 9:  strcpy(timePhrase, PSTR(" IT IS THE EIGHTEENTH BRUMAIRE  ")); // also Attica uprising
          break;
        case 11: strcpy(timePhrase, PSTR("NEVER FORGET                9/11")); // also Enkutatash, Ethiopian/Eritrean New Year
          break;
        case 12: strcpy(timePhrase, PSTR("   HAPPY BIRTHDAY JESSE OWENS   "));
          break;
        case 13: strcpy(timePhrase, PSTR("     THE IDES OF SEPTEMBER      "));
          break;
        case 14: strcpy(timePhrase, PSTR(" HAPPY BIRTHDAY MARGARET SANGER ")); // https://en.wikipedia.org/wiki/Margaret_Sanger
          break;
        case 15: strcpy(timePhrase, PSTR("   GUATEMALA INDEPENDENCE DAY   "));
          break;
        case 16: strcpy(timePhrase, PSTR("VIVA LA INDEPENDENCIA DE MEXICO ")); // Mexican Independence Day
          break;
        case 17: strcpy(timePhrase, PSTR("     HAPPY CONSTITUTION DAY     ")); // also feast day of Hildegard von Bingen
          break;
        case 18: strcpy(timePhrase, PSTR(" VIVA LA INDEPENDENCIA DE CHILE ")); // Chile Independence Day
          break;
        case 19: strcpy(timePhrase, PSTR("AHOY ME MATIES     AAAAAARRRRRRR")); // talk like a priate day
          break;
        case 20: strcpy(timePhrase, PSTR("BATTLE OF THE SEXES WAS IN 1973 ")); //
          break;
        case 21: strcpy(timePhrase, PSTR("      HAPPY WORLD PEACE DAY     "));
          break;
        case 22: strcpy(timePhrase, PSTR("      HAPPY AUTUMNAL EQUINOX    ")); // can move a bit
          break;
        case 23: strcpy(timePhrase, PSTR(" HAPPY BISEXUAL VISIBILITY DAY  ")); // also John Coltrane's birthday
          break;
        case 24: strcpy(timePhrase, PSTR(" GUINEA-BISSAU INDEPENDENCE DAY ")); // https://en.wikipedia.org/wiki/Independence_Day_(Guinea-Bissau)
          break;
        case 25: strcpy(timePhrase, PSTR("    HAPPY ONE-HIT WONDER DAY    ")); //
          break;
        case 26: strcpy(timePhrase, PSTR(" CONCORDE ATLANTIC CROSSING DAY ")); //
          break;
        case 27: strcpy(timePhrase, PSTR(" TURKMENISTAN INDEPENDENCE DAY  ")); // https://en.wikipedia.org/wiki/Independence_Day_(Turkmenistan)
          break;
        case 29: strcpy(timePhrase, PSTR("   HAPPY BIRTHDAY LECH WALESA   "));
          break;
        case 30: strcpy(timePhrase, PSTR("   BOTSWANA INDEPENDENCE DAY    ")); // https://en.wikipedia.org/wiki/Independence_Day_(Botswana)
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
        case 4:  strcpy(timePhrase, PSTR("SPUTNIK 1 LAUNCHED TODAY IN 1957")); // also https://en.wikipedia.org/wiki/Independence_Day_(Lesotho)
          break;
        case 5:  strcpy(timePhrase, PSTR("   HAPPY BIRTHDAY VACLAV HAVEL  "));
          break;
        case 6:  strcpy(timePhrase, PSTR("      HAPPY MAD HATTER DAY      "));
          break;
        case 7:  strcpy(timePhrase, PSTR(" SLAVERY ABOLISHED IN CUBA 1886 "));
          break;
        case 8:  strcpy(timePhrase, PSTR(" DAY OF THE CROATIAN PARLIAMENT ")); // https://www.sabor.hr/en/about-parliament/history/important-dates/8-october-croatian-parliament-day
          break;
        case 9:  strcpy(timePhrase, PSTR("     HAPPY LEIF ERIKSON DAY     "));
          break;
        case 10: strcpy(timePhrase, PSTR("      IT IS MORRISSEY DAY       ")); // also https://en.wikipedia.org/wiki/National_Day_of_the_Republic_of_China
          break;
        case 11: strcpy(timePhrase, PSTR(" HAPPY INDIGENOUS PEOPLES' DAY  ")); // also https://en.wikipedia.org/wiki/Meditrinalia
          break;
        case 12: strcpy(timePhrase, PSTR("      IT IS COLUMBUS DAY        "));
          break;
        case 13: strcpy(timePhrase, PSTR("       HAPPY NO BRA DAY         ")); // also https://en.wikipedia.org/wiki/Fontinalia
          break;
        case 14: strcpy(timePhrase, PSTR("    HAPPY WORLD STANDARDS DAY   "));
          break;
        case 15: strcpy(timePhrase, PSTR("    HAPPY BIRTHDAY FELA KUTI    ")); // also Nietzsche's birthday
          break;
        case 16: strcpy(timePhrase, PSTR("   HAPPY BIRTHDAY OSCAR WILDE   "));
          break;
        case 17: strcpy(timePhrase, PSTR("      IT IS DESSALINES DAY      "));
          break;
        case 18: strcpy(timePhrase, PSTR(" BOXER REBELLION BEGAN IN 1899  ")); // https://en.wikipedia.org/wiki/Boxer_Rebellion
          break;
        case 19: strcpy(timePhrase, PSTR("       FELIX ARMILUSTRIUM       ")); // https://en.wikipedia.org/wiki/Armilustrium
          break;
        case 20: strcpy(timePhrase, PSTR("       HAPPY CALVADOS DAY       "));
          break;
        case 21: strcpy(timePhrase, PSTR("        IT IS APPLE DAY         ")); // also Back to the Future Day
          break;
        case 22: strcpy(timePhrase, PSTR("     HAPPY NATIONAL NUT DAY     "));
          break;
        case 23: strcpy(timePhrase, PSTR("         HAPPY MOLE DAY         ")); // Celebrated annually on October 23 from 6:02 a.m. to 6:02 p.m., Mole Day commemorates Avogadro's Number (6.02 x 10²³)
          break;
        case 24: strcpy(timePhrase, PSTR("    IT IS UNITED NATIONS DAY    "));
          break;
        case 25: strcpy(timePhrase, PSTR("  HAPPY BIRTHDAY PABLO PICASSO  ")); // also Retrocession Day
          break;
        case 26: strcpy(timePhrase, PSTR("  IT IS INTERSEX AWARENESS DAY  "));
          break;
        case 27: strcpy(timePhrase, PSTR("NYC SUBWAY OPENED TODAY IN 1904 "));
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
        case 3:  strcpy(timePhrase, PSTR("LAIKA SENT TO SPACE ON SPUTNIK 2")); // https://en.wikipedia.org/wiki/Laika
          break;
        case 4:  strcpy(timePhrase, PSTR("IT IS YITZHAK RABIN MEMORIAL DAY"));
          break;
        case 5:  strcpy(timePhrase, PSTR("REMEMBER REMEMBER THE 5TH OF NOV")); // Guy Fawkes Day
          break;
        case 6:  strcpy(timePhrase, PSTR("     GLAD GUSTAV ADOLFSDAGEN    ")); // Gustavus Adolphus Day
          break;
        case 7:  strcpy(timePhrase, PSTR(" IT IS OCTOBER REVOLUTION DAY   "));
          break;
        case 8:  strcpy(timePhrase, PSTR("   HAPPY BIRTHDAY DOROTHY DAY   "));
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
        case 14: strcpy(timePhrase, PSTR("  HAPPY BIRTHDAY LOUISE BROOKS  ")); // https://en.wikipedia.org/wiki/Louise_Brooks
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
        case 21: strcpy(timePhrase, PSTR("      HAPPY BIRTHDAY BJORK      ")); // also Arpanet invented in 1969
          break;
        case 22: strcpy(timePhrase, PSTR("JFK WAS ASSASSINATED ON THIS DAY"));
          break;
        case 23: strcpy(timePhrase, PSTR("  HAPPY BIRTHDAY EL LISSITZKY   "));
          break;
        case 24: strcpy(timePhrase, PSTR("      HAPPY EVOLUTION DAY       "));
          break;
        case 25: strcpy(timePhrase, PSTR("   HAPPY EVACUATION DAY NYC     ")); // https://en.wikipedia.org/wiki/Evacuation_Day_(New_York) also ELIAN GONZALEZ WAS FOUND AT SEA
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
        case 3:  strcpy(timePhrase, PSTR("         FELIX BONA DEA         ")); // also Bhopal Disaster Day
          break;
        case 4:  strcpy(timePhrase, PSTR("HAPPY BIRTHDAY CHIEF CRAZY HORSE"));
          break;
        case 5:  strcpy(timePhrase, PSTR("      GRUSS VOM KRAMPUS         ")); // also Repeal Day
          break;
        case 6:  strcpy(timePhrase, PSTR("    FINLAND INDEPENDENCE DAY    ")); // https://en.wikipedia.org/wiki/Independence_Day_(Finland)
          break;
        case 7:  strcpy(timePhrase, PSTR("A DATE THAT WILL LIVE IN INFAMY "));
          break;
        case 8:  strcpy(timePhrase, PSTR("       HAPPY BODHI DAY          ")); // Sinead O'Connor's birthday
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
        case 19: strcpy(timePhrase, PSTR("    HAPPY GOA LIBERATION DAY    ")); // https://en.wikipedia.org/wiki/Goa_Liberation_Day - also https://en.wikipedia.org/wiki/Opalia
          break;
        case 20: strcpy(timePhrase, PSTR("       HAPPY FOREFEAST          ")); // also first website created
          break;
        case 21: strcpy(timePhrase, PSTR("     MERRY WINTER SOLSTICE      ")); // also https://en.wikipedia.org/wiki/Divalia
          break;
        case 22: strcpy(timePhrase, PSTR("INDIA'S NATIONAL MATHEMATICS DAY")); // https://en.wikipedia.org/wiki/National_Mathematics_Day_(India)
          break;
        case 23: strcpy(timePhrase, PSTR("IT'S FESTIVUS FOR THE REST OF US"));
          break;
        case 24: strcpy(timePhrase, PSTR("     MERRY CHRISTMAS EVE        "));
          break;
        case 25: strcpy(timePhrase, PSTR("        MERRY CHRISTMAS         "));
          break;
        case 26: strcpy(timePhrase, PSTR("        HAPPY BOXING DAY        ")); // 1st day of Kwanzaa
          break;
        case 27: strcpy(timePhrase, PSTR("HAPPY BIRTHDAY MARLENE DIETRICH "));
          break;
        case 28: strcpy(timePhrase, PSTR("   HAPPY BIRTHDAY LIU XIAOBO    "));
          break;
        case 29: strcpy(timePhrase, PSTR("  THE BATTLE OF WOUNDED KNEE    ")); // https://en.wikipedia.org/wiki/Wounded_Knee_Massacre
          break;
        case 30: strcpy(timePhrase, PSTR("           RIZAL DAY            ")); // https://en.wikipedia.org/wiki/Rizal_Day
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
