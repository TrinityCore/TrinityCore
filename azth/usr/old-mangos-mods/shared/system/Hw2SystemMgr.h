#ifndef HW2SYSTEMMGR_H
#define HW2SYSTEMMGR_H

#include "Common.h"
#include "LootMgr.h"

class ScriptObject;
class Player;
class Unit;
class Creature;

#define LOOT_MIN 3
#define LOOT_MAX 6 // da moltiplicare con il rate loot.referenced

#define STANDARD   20

enum ScriptsId
{
    GUARD1_ID = 4000,
};


enum Azeroth_Values
{
   AZEROTH_TOURNAMENT = 800002,
   AZEROTH_AIUTANTE = 800002,
   MONASTERO = 44, //MAPPA
   ISOLE = 2317, // AREA
   HYJAL = 616, //ZONA - AREA
   FRENESIA_MAX = 6,
   AURA_FRENESIA = 40735,  //defias and enraged
   DEMONIC_FRENZY = 23257,
   ELECTROMEDAL = 37248,
   SPELL_DAMAGE = 40142,

   P_SUICIDIO = 5,
   P_UCCISIONE = 3,
};


/* configurazioni per i mod del torneo:
   tipi:
     0 -> torneo esteso 
	 1 -> torneo esteso per adv  NON UTILIZZATA   SOstituita con : guadagno honor da gruppi
	 2 -> gruppi
	 3 -> raid
	 4 -> duelli
	 5 -> flag FFA_PVP nelle zone tournament.
	 6 -> GuildInstance Attiva/disattiva  < non attivo
	 7 -> Isole Tanaris Attiva/disattiva  < non attivo
*/


/* configurazioni per i mod rpg:
   tipi:
     0 -> loot system
	 1 -> attiva controllo loot duplicati
	 2 -> attiva guadagno credito dalle quest
	 3 -> attiva il servizio di teleport
	 4 -> attiva il moltiplicatore di esperienza gruppo
*/

class Hw2Class
{
	public:
		
        Hw2Class();
        ~Hw2Class();

        typedef struct act {
                uint32 indice, loc_id ;
                uint8 loc_type,speak_type;
                uint16 flag , min_rep_rank, max_rep_rank , language ,  emote_id_1, emote_id_2;
                float chance;
                std::string *text_male,*text_female,*txt_emote_m,*txt_emote_f;
            struct act *next;
        } action;

        struct classifica 
        {
                std::string *Titolo[2]; // 2 = maschio/femmina
                int32 grado;
        };


        //variabili

        uint32 count_list,ConfCount;
        struct act *lista;
        struct classifica cl[STANDARD];
        uint16 cl_count;
        bool AzConf[STANDARD],ListFilled,TrMod[STANDARD];
        std::string ConfDef[STANDARD];
        time_t m_modGameTime;
        uint32 timerCambiaOra;
        int newHr;
        float x,y,z; // usate per getclosepoint

        typedef std::map<uint32, class T*> ScriptMap;
        static ScriptMap scriptList;


		//procedure

        //lista rpg
        int dlstore(struct act **start);
        int dlprocess(uint16 flag, Player *pl, Creature *cr, struct act *start);
        int InitList() { return dlstore(&lista); }
        int ProcessList(uint16 flag, Player *pl, Creature *cr) { return dlprocess(flag,pl,cr,lista); }

        //special function
        Player * AzerothSelectNearbyFrTarget(Unit* unit) const;
        std::list<Unit *> SelectNearbyTargets(Unit* unit, uint8 tipo, float distanza) const;
        uint64 HandleFindPlayer(const char* stringa, Player *Pl, Player *SelPl);
        bool AzDumpWrite(Player *pl,const char* args);
        bool AzDumpLoad(Player *pl,const char* args);
        std::string CreaStringaComposta(const char *format, ...);
        bool DoubleLoot(LootStoreItem const & i, std::vector<LootItem> quest_items,std::vector<LootItem> items);
        uint16 ProcessaRefCount(LootStoreItemList Entries,uint16 *tot,uint16 *count, float rate);
        uint16 ProcessaGruppi(Loot& loot,float rate);

        static void setScriptList(std::map<uint32, class T*> sList);
        static ScriptObject* getScript(const char* name);

        // azeroth (generale)
        uint8 CheckAcc(Player *player,uint8 type);
        bool ImpostaGiocatore(Player *pl);
        bool Hw2Config(bool start,uint8 mode=0,uint8 tipo=0,bool scelta=false);
        time_t const& GetModGameTime() const { return m_modGameTime; }
        void Update(uint32 diff);
        void RemoveCharFromDB(uint32 lowguid);
        void Hw2SendSysMessage(Player *target,const char* msg, ...);
        void Hw2SendSysMessage(Player *target, int32 msg, ...);
        void LevelUpdates(Player *pl);

        static Hw2Class *GetHw2();
		
        //rpg functions
        bool RpgFunzioneIniziale(Player *pl);
        bool RpgModificaPT(bool salva,uint64 guid,int32 credito,int32 totale,bool indirect_pt=false, Player *Modder=NULL);
        bool RpgModIdentity(uint64 guid,char* stringa,Player *pl);

        bool RpgGestioneEmote(Player *pl,uint32 emote);
        bool RpgVisualizzaProfilo(Player* pl,Player* selected);
        bool RpgSetSupervisor(uint64 guid, uint64 supervisor,Player *Modder,bool Force=false);
        bool RpgAggiornaUpLine(uint64 guid,bool salva=false,float punti=0);
        bool RpgProfiloOffLine(uint64 guid,Player *Modder);
        int32 RpgContaDownLine(uint64 guid,uint16 pl_rango);
        uint16 RpgTrovaRank(int32 TotRpg);

        //Tournament Functions
        void DmAzerothPlayerInfo(Player *pl);
        bool DmIsTourn(Player *pl);
        void DmPlayerInfo(Player *pl);
        void DmAddItemSet(Player* plTarget , uint32 itemsetId);
        void DmCreaPet(Player *pl,Creature *Pet);
        void DmAddSpell(Player *pl,bool tutte=false,uint32 npclista=0);
        void DmSvuotaBorse(Player *plTarget);
        void DmSetTournament(Player *pl);
        void DmGestionePunti(Player *pl,bool SalvaSulDb=false,bool HonorKill=true,Player *soggetto=NULL,bool suicidio=false);
        void DmGestioneSpawning(Player *pl,uint32 zona);
        bool DmGestioneMusica(Player *pl,uint32 suono);
        bool DmCheckTournament(Player *pl, bool tele, uint32 mapid = -1);



	protected:

	private:
};

#define sHw2 ACE_Singleton<Hw2Class, ACE_Null_Mutex>::instance()

#endif
