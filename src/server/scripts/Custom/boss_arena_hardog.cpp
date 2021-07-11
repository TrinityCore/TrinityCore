/* ScriptData
 SDName: Szerelmes
 SD%Complete:
 Update 15/02/13 à 23h
 SDComment: Quest support: (id=44)
 SDCategory: Arenes
 EndScriptData */

/*

//{ ContentData !

 NPC
 npc_szerelmes (id=31)
 npc_Gladiateur (id=32)
 npc_hulrik (id=33)
 npc_laska (id=65)
 npc_karlek(id=67)

 OBJETS
 Porte de l'event (id=99000)
 Ligne Rouge (id=99100)
 Feu D'artifice Bleu (id=99200)
 Feu D'artifice Rouge (id=99210)
 Feu D'artifice Jaune (id=99220)
 Feu D'artifice Verte (id=99230)
 Feu D'artifice Blanche (id=99240)
 Feu D'artifice Violette (id=99250)
 FireWork Visuel(id=99300)
 Table (id=99500)
 Livres (id=99510)
 Parchemin (id=99520)
 Chaises (id=99530)
 Candelabre (id=99540)
}
// Fin ContentData !

//{ AJOUT SQL !

//--------------------------------------------------------
// QUETES :
//--------------------------------------------------------
// Quête 44
INSERT INTO `quest_template` VALUES (44, 2, 1637, 60, 60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Defi : Szerelmes', 'Il est temps de révèler votre talent, $N. Pensez vous être a la hauteur du défi que je vous prépares ?\r\n\r\nVous vous en sentez capable ? Très bien, écoutez moi alors ! je vais appeler notre champion en titre, mais attention vous n\'avez que très peu de temps pour le défié.\r\n\r\nParlez à Mac\'fly lorsque vous serez pret, il sera en mesure de vous téléporter dans notre aréne.', 'Combattre Szerelmes en moins de 2 minutes, et devenir le nouveau champion de l\'arêne pour ainsi démontrer votre domination.', 'Quel magnifique combat ! J\'en ai eu le souffle coupé ! $B$B Vous avez reçu toute ma gratitude $N !', 'Comment se porte Szerelmes ? Toujours en vie ?! ', '', 'Prouvez votre talent', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 250, 0, 0, 0, 0, 25, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
//--------------------------------------------------------
// CREATURES :
//--------------------------------------------------------
// npc_szerelmes (id=31)
INSERT INTO `creature_template` VALUES (31, 0, 0, 413, 413, 'Szerelmes', 'Champion de l\'arêne', 0, 60, 60, 32800, 32800, 0, 0, 0, 14, 14, 0, 1, 1.14286, 4, 3, 0, 298, 127, 175, 1.4, 1500, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 'arena_szerelmes');
// npc_Gladiateur (id=32)
INSERT INTO `creature_template` VALUES (32, 0, 0, 10820, 0, 'Sbire asservis', '', 0, 60, 60, 1050, 1600, 0, 0, 0, 14, 14, 0, 1, 1.14286, 0, 0, 90, 150, 0, 27, 1, 2000, 1600, 0, 0, 0, 0, 0, 0, 0, 0, 20, 20, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'AggressorA', 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, '');
// npc_hulrik (id=33)
INSERT INTO `creature_template` VALUES (33, 0, 0, 4602, 4602, 'Hulrick', 'Le Barbarre', 0, 60, 60, 4500, 4500, 0, 0, 556, 35, 35, 2, 1, 1.14286, 1.1, 0, 0, 0, 0, 10, 1, 2000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, '');
// npc_laska (id=34)
INSERT INTO `creature_template` VALUES (34, 0, 0, 1298, 0, 'Laska', '', 0, 60, 60, 413, 413, 0, 0, 20, 35, 35, 3, 0.96, 1.14286, 0, 0, 0, 13, 0, 5, 1, 1500, 0, 1, 4608, 0, 0, 0, 0, 0, 0, 16.808, 23.111, 100, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 'npc_laska');
// npc_karlek(id=35)
INSERT INTO `creature_template` VALUES (35, 0, 0, 1298, 0, 'Karlek', '', 0, 60, 60, 413, 413, 0, 0, 20, 35, 35, 3, 0.96, 1.14286, 0, 0, 0, 13, 0, 5, 1, 1500, 0, 1, 4608, 0, 0, 0, 0, 0, 0, 16.808, 23.111, 100, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 'npc_karlek');
//--------------------------------------------------------
//LOCALISATION PNJ : guid possible >70000 & < 70500
//--------------------------------------------------------
npc_hulrik (id=33)
INSERT INTO `creature` VALUES (70000, 33, 1, 0, 0, 2170.1, -4799.45, 54.9116, 1.34271, 120, 5, 0, 9999, 0, 0, 0);
// npc_laska (id=34)
INSERT INTO `creature` VALUES (70001, 34, 1, 0, 0, 2158.15, -4752.41, 54.9, 5.68667, 25, 5, 0, 413, 0, 0, 0);
// npc_karlek(id=35)
INSERT INTO `creature` VALUES (70002, 35, 1, 0, 0, 2206.18, -4778.47, 65.1889, 4.80406, 120, 5, 0, 413, 0, 0, 0);
//--------------------------------------------------------
// GAMEOBJECTS :
//--------------------------------------------------------
//L'INTERRIEUR DE ARENE! guid possible >99000 & < 100000
//--------------------------------------------------------
//PORTES INTERRIEURS ARENA
INSERT INTO `gameobject_template` VALUES (99000, 0, 411, 'Porte de l\'event', 0, 32, 2, 0, 0, 196608, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
//Localisation des portes
INSERT INTO `gameobject` VALUES (270100, 99000, 1, 2145.31, -4767.17, 61.9296, 3.21618, 0, 0, 0.999305, -0.0372875, 25, 100, 1);
INSERT INTO `gameobject` VALUES (270101, 99000, 1, 2165.73, -4734.14, 61.8067, 1.95562, 0, 0, 0.829274, 0.558842, 25, 100, 1);
//Ligne Rouge
INSERT INTO `gameobject_template` VALUES (99100, 5, 5453, 'Ligne de Securite', 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
//Localisation Ligne Rouge
INSERT INTO `gameobject` VALUES (271100, 99100, 1, 2200.33, -4792.03, 64.7625, 2.16194, 0, 0, 0.882414, 0.470473, 25, 100, 1);
INSERT INTO `gameobject` VALUES (271101, 99100, 1, 2212.07, -4773.16, 64.7608, 6.09835, 0, 0, 0.0922849, -0.995733, 25, 100, 1);
//--------------------------------------------------------
//FireWorks
//--------------------------------------------------------
//Visuel
INSERT INTO `gameobject_template` VALUES (99300, 3, 6607, 'Baril D\'artifice', 0, 0, 1, 57, 22909, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
//BLUE
INSERT INTO `gameobject_template` VALUES (99200, 10, 6515, 'Feu D\'artifice, Grande Bleu', 0, 0, 2, 0, 0, 0, 196608, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
//RED
INSERT INTO `gameobject_template` VALUES (99210, 10, 6509, 'Feu D\'artifice, Grande Rouge', 0, 0, 2, 0, 0, 0, 196608, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
//YELLOW
INSERT INTO `gameobject_template` VALUES (99220, 10, 6523, 'Feu D\'artifice, Grande Jaune', 0, 0, 2, 0, 0, 0, 196608, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
//GREEN
INSERT INTO `gameobject_template` VALUES (99230, 10, 6517, 'Feu D\'artifice, Grande Verte', 0, 0, 2, 0, 0, 0, 196608, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
//WHITE
INSERT INTO `gameobject_template` VALUES (99240, 10, 6519, 'Feu D\'artifice, Grande Blanche', 0, 0, 2, 0, 0, 0, 196608, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
//PURPLE
INSERT INTO `gameobject_template` VALUES (99250, 10, 6522, 'Feu D\'artifice, Grande Violette', 0, 0, 1, 0, 0, 0, 196608, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
//--------------------------------------------------------
//Localisation de FireWorks
//--------------------------------------------------------
//BLUE
INSERT INTO `gameobject` VALUES (271200, 99200, 1, 2179.69, -4787.67, 54.9109, 1.52107, 0, 0, 0.68931, 0.724467, 25, 100, 1);
INSERT INTO `gameobject` VALUES (271201, 99200, 1, 2166.53, -4784.62, 54.9108, 1.16764, 0, 0, 0.551216, 0.834362, 25, 100, 1);
INSERT INTO `gameobject` VALUES (271202, 99200, 1, 2190.59, -4745.60, 54.9108, 3.80502, 0, 0, 0.945485, -0.325666, 25, 100, 1);
INSERT INTO `gameobject` VALUES (271203, 99200, 1, 2199.57, -4756.22, 54.9108, 3.95268, 0, 0, 0.918888, -0.394518, 25, 100, 1);
//RED
INSERT INTO `gameobject` VALUES (271210, 99210, 1, 2179.69, -4787.67, 54.9109, 1.52107, 0, 0, 0.68931, 0.724467, 25, 100, 1);
INSERT INTO `gameobject` VALUES (271211, 99210, 1, 2166.53, -4784.62, 54.9108, 1.16764, 0, 0, 0.551216, 0.834362, 25, 100, 1);
INSERT INTO `gameobject` VALUES (271212, 99210, 1, 2190.59, -4745.60, 54.9108, 3.80502, 0, 0, 0.945485, -0.325666, 25, 100, 1);
INSERT INTO `gameobject` VALUES (271213, 99210, 1, 2199.57, -4756.22, 54.9108, 3.95268, 0, 0, 0.918888, -0.394518, 25, 100, 1);
//YELLOW
INSERT INTO `gameobject` VALUES (271220, 99220, 1, 2179.69, -4787.67, 54.9109, 1.52107, 0, 0, 0.68931, 0.724467, 25, 100, 1);
INSERT INTO `gameobject` VALUES (271221, 99220, 1, 2166.53, -4784.62, 54.9108, 1.16764, 0, 0, 0.551216, 0.834362, 25, 100, 1);
INSERT INTO `gameobject` VALUES (271222, 99220, 1, 2190.59, -4745.60, 54.9108, 3.80502, 0, 0, 0.945485, -0.325666, 25, 100, 1);
INSERT INTO `gameobject` VALUES (271223, 99220, 1, 2199.57, -4756.22, 54.9108, 3.95268, 0, 0, 0.918888, -0.394518, 25, 100, 1);
//GREEN
INSERT INTO `gameobject` VALUES (271230, 99230, 1, 2179.69, -4787.67, 54.9109, 1.52107, 0, 0, 0.68931, 0.724467, 25, 100, 1);
INSERT INTO `gameobject` VALUES (271231, 99230, 1, 2166.53, -4784.62, 54.9108, 1.16764, 0, 0, 0.551216, 0.834362, 25, 100, 1);
INSERT INTO `gameobject` VALUES (271232, 99230, 1, 2190.59, -4745.60, 54.9108, 3.80502, 0, 0, 0.945485, -0.325666, 25, 100, 1);
INSERT INTO `gameobject` VALUES (271233, 99230, 1, 2199.57, -4756.22, 54.9108, 3.95268, 0, 0, 0.918888, -0.394518, 25, 100, 1);
//WHITE
INSERT INTO `gameobject` VALUES (271240, 99240, 1, 2179.69, -4787.67, 54.9109, 1.52107, 0, 0, 0.68931, 0.724467, 25, 100, 1);
INSERT INTO `gameobject` VALUES (271241, 99240, 1, 2166.53, -4784.62, 54.9108, 1.16764, 0, 0, 0.551216, 0.834362, 25, 100, 1);
INSERT INTO `gameobject` VALUES (271242, 99240, 1, 2190.59, -4745.60, 54.9108, 3.80502, 0, 0, 0.945485, -0.325666, 25, 100, 1);
INSERT INTO `gameobject` VALUES (271243, 99240, 1, 2199.57, -4756.22, 54.9108, 3.95268, 0, 0, 0.918888, -0.394518, 25, 100, 1);
//PURPLE
INSERT INTO `gameobject` VALUES (271250, 99250, 1, 2179.69, -4787.67, 54.9109, 1.52107, 0, 0, 0.68931, 0.724467, 25, 100, 1);
INSERT INTO `gameobject` VALUES (271251, 99250, 1, 2166.53, -4784.62, 54.9108, 1.16764, 0, 0, 0.551216, 0.834362, 25, 100, 1);
INSERT INTO `gameobject` VALUES (271252, 99250, 1, 2190.59, -4745.60, 54.9108, 3.80502, 0, 0, 0.945485, -0.325666, 25, 100, 1);
INSERT INTO `gameobject` VALUES (271253, 99250, 1, 2199.57, -4756.22, 54.9108, 3.95268, 0, 0, 0.918888, -0.394518, 25, 100, 1);
//--------------------------------------------------------
//L'ENTREE DE ARENE!
//--------------------------------------------------------
//Table
INSERT INTO `gameobject_template` VALUES (99500, 5, 221, 'Table', 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
//Livres
INSERT INTO `gameobject_template` VALUES (99510, 2, 43, 'Livres du Tournoi', 1, 0, 1, 0, 205, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
//Parchemin
INSERT INTO `gameobject_template` VALUES (99520, 5, 163, 'Parchemin des inscriptions', 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
//Chaises
INSERT INTO `gameobject_template` VALUES (99530, 7, 91, 'Chaise', 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
//Candelabre
INSERT INTO `gameobject_template` VALUES (99540, 5, 240, 'Chandelier', 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
//Localisation ENTREE ARENE
//Table
INSERT INTO `gameobject` VALUES (3996182, 99500, 1, 2145.79, -4744.25, 50.4952, 2.60338, 0, 0, 0.964009, 0.265871, 25, 100, 1);
//Livres du Tournoi
INSERT INTO `gameobject` VALUES (3996183, 99510, 1, 2145.98, -4743.13, 51.4853, 1.91222, 0, 0, 0.816955, 0.576702, 25, 100, 1);
//Parchemin des inscriptions
INSERT INTO `gameobject` VALUES (3996184, 99520, 1, 2145.27, -4744.09, 51.4943, 2.6128, 0, 0, 0.965251, 0.261326, 25, 100, 1);
//Chaise
INSERT INTO `gameobject` VALUES (3996186, 99530, 1, 2147.42, -4745.3, 50.496, 2.64421, 0, 0, 0.969236, 0.246135, 25, 100, 1);
//Chandelier
INSERT INTO `gameobject` VALUES (3996187, 99540, 1, 2144.36, -4744.92, 51.5089, 5.75439, 0, 0, 0.261329, -0.96525, 25, 100, 1);
*/
//}
// FIN DES AJOUTS SQL !

#include "scriptPCH.h"

#define SHOW_GOSSIP(a) player->SEND_GOSSIP_MENU(a, pCreature->GetObjectGuid())

/*
Last Updated le 17/02/13 13h!
      Reste à faire :
      - Si le joueur meurt, l'évent doit s'arréter et le cadavre du joueur se fait teleporter hors de l'arene.
      - Si le joueur est aidé, l'évent doit s'arréter et les joueurs se font teleporter hors de l'arene.
      - Les adds doivent despawn à la fin de l'event.
      - Laska doit télèporter les joueurs, si l'event est annulé ou complété, mais pas pendant que l'event est lancé.
      - L'event doit se stopper pas si la quête est echoué ou complèté.

*/
// corner, sud
#define ADD_1X 2200.113281f
#define ADD_1Y -4761.684570f
#define ADD_1Z 54.910847f
#define ADD_1O 3.573156f
//corner, est
#define ADD_2X 2184.825928f
#define ADD_2Y -4786.309570f
#define ADD_2Z 54.911507f
#define ADD_2O 1.381106f
// corner, nord
#define ADD_3X 2162.641602f
#define ADD_3Y -4780.766113f
#define ADD_3Z 54.911507f
#define ADD_3O 0.875304f
//corner, ouest
#define ADD_4X 2162.64160f
#define ADD_4Y -4780.766113f
#define ADD_4Z 54.911507f
#define ADD_4O 0.875304f

#define SPELL_KNOCKAWAY  10101
#define SPELL_PUMMEL     15615
//#define SPELL_SHOOT      20463
#define SPELL_FAIL       91599

typedef enum
{
    EVENT_NOT_STARTED,
    EVENT_STARTED,
    EVENT_COMPLETE
} ArenaBossSzerelmesStatus;

/*#########################
## npc_Szerelmes
##########################*/

enum
{
    NPC_ADD = 32
};

struct arena_szerelmesAI : public ScriptedAI
{
    arena_szerelmesAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 KnockAway_Timer;
    uint32 Pummel_Timer;
    uint32 Shoot_Timer;
    uint32 add_Timer;

    void Reset() override
    {
        Shoot_Timer = 15000;
        Pummel_Timer = 7000;
        KnockAway_Timer = 11000;
        add_Timer = 60000;
    }

    void Aggro(Unit* pPlayer) override
    {
        add_Timer = 1000;
        DoCastSpellIfCan(m_creature->GetVictim(), SPELL_FAIL);
    }

    void JustDied(Unit* Victim) override
    {
        while (Creature* Add = m_creature->FindNearestCreature(NPC_ADD, 100.0f))
            Add->DisappearAndDie();
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (Pummel_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_PUMMEL) == CAST_OK)
                Pummel_Timer = 12000;
        }
        else
            Pummel_Timer -= diff;

        if (KnockAway_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_KNOCKAWAY) == CAST_OK)
                KnockAway_Timer = 14000;
        }
        else
            KnockAway_Timer -= diff;

        /* enlevé car trop dure!
                if (Shoot_Timer < diff)
                {
                    DoCastSpellIfCan(m_creature->GetVictim(),SPELL_SHOOT);
                    Shoot_Timer = 2000;
                }
                else
                    Shoot_Timer -= diff;
        */
        //---------------------------------------------------------------------------------------------------------
        //                           LES ADDS !!!!!!!
        //---------------------------------------------------------------------------------------------------------

        if (add_Timer < diff)
        {
            switch (urand(0, 4))
            {
                case 0:
                    m_creature->SummonCreature(32, ADD_1X, ADD_1Y, ADD_1Z, ADD_1O, TEMPSUMMON_TIMED_DESPAWN, 60000);
                    m_creature->SummonCreature(32, ADD_3X, ADD_3Y, ADD_3Z, ADD_3O, TEMPSUMMON_TIMED_DESPAWN, 60000);
                    break;
                case 1:
                    m_creature->SummonCreature(32, ADD_2X, ADD_2Y, ADD_2Z, ADD_2O, TEMPSUMMON_TIMED_DESPAWN, 60000);
                    m_creature->SummonCreature(32, ADD_4X, ADD_4Y, ADD_4Z, ADD_4O, TEMPSUMMON_TIMED_DESPAWN, 60000);
                    break;
                case 2:
                    m_creature->SummonCreature(32, ADD_1X, ADD_1Y, ADD_1Z, ADD_1O, TEMPSUMMON_TIMED_DESPAWN, 60000);
                    m_creature->SummonCreature(32, ADD_3X, ADD_3Y, ADD_3Z, ADD_3O, TEMPSUMMON_TIMED_DESPAWN, 60000);
                    break;
                case 3:
                    m_creature->SummonCreature(32, ADD_2X, ADD_2Y, ADD_2Z, ADD_2O, TEMPSUMMON_TIMED_DESPAWN, 60000);
                    m_creature->SummonCreature(32, ADD_4X, ADD_4Y, ADD_4Z, ADD_4O, TEMPSUMMON_TIMED_DESPAWN, 60000);
                    break;
            }
            add_Timer = 30000;
        }
        else
            add_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};


CreatureAI* GetAI_arena_szerelmes(Creature* pCreature)
{
    return new arena_szerelmesAI(pCreature);
}

/*##############################
## npc_Karlek
##############################*/
enum
{
    npc_karlek_HELLO = 1,
    npc_karlek_ERROR = 1,
    npc_karlek_OK    = 1,
    npc_szerelmes    = 31,
};

struct npc_karlekAI : public ScriptedAI
{
    npc_karlekAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
        ResetEvent();
    }

    ObjectGuid m_playerGUID;
    ObjectGuid m_uiSzerelmesGUID;
    ObjectGuid m_uiOldOldSverelmesGUID;
    ArenaBossSzerelmesStatus eEventStatus;
    uint32 m_uiEventResetTimer;

    void Reset() override
    {
    }

    ArenaBossSzerelmesStatus GetEventStatus()
    {
        return eEventStatus;
    }

    void ResetEvent()
    {
        eEventStatus = EVENT_NOT_STARTED;
        // m_uiOldSzerelmesGUID = m_uiSzerelmesGUID;
        if (Creature* pSzerelmes = m_creature->GetMap()->GetCreature(m_uiSzerelmesGUID))
            pSzerelmes->ForcedDespawn();

        m_uiSzerelmesGUID.Clear();
        m_playerGUID.Clear();

    }

    void StartEvent(Player *pPlayer)
    {
        if (pPlayer)
        {
            m_playerGUID = pPlayer->GetGUID();
            pPlayer->TeleportTo(1, 2191.9f, -4773.4f, 54.9f, 2.56f);
        }

        // Verifier que le mob ne soit pas deja pop!
        // Le Boss pop et depop 25 secondes aprés si il reste hors combat.
        if (Creature * pSzerelmes = m_creature->SummonCreature(npc_szerelmes, 2206.47f, -4741.44f, 54.90f, 3.88f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000))
        {
            m_uiSzerelmesGUID = pSzerelmes->GetObjectGuid();
            eEventStatus = EVENT_STARTED;
        }
    }
// Ne fonctionne pas!
    void CompleteEvent()
    {
        m_uiEventResetTimer = 30000;
        if (Player* pPlayer = m_creature->GetMap()->GetPlayer(m_playerGUID))
        {
            char sMessage[200];
            sprintf(sMessage, "Nous avons un nouveau champion !");
        }
        eEventStatus = EVENT_COMPLETE;
    }

    // L'event se reset si le boss despawn.
    void SummonedCreatureDespawn(Creature* pSummoned) override
    {
        if (pSummoned->GetObjectGuid() == m_uiSzerelmesGUID)
        {
            m_creature->MonsterTextEmote("Vous me faites perdre mon temps !", nullptr);
            ResetEvent();
        }
    }

    // L'event se complete si le boss meurt.
    void SummonedCreatureJustDied(Creature* pSummoned) override
    {
        if (pSummoned->GetObjectGuid() == m_uiSzerelmesGUID)
            CompleteEvent();
    }


    void UpdateAI(uint32 const diff) override
    {
        if (Creature* pSzerelmes = m_creature->GetMap()->GetCreature(m_uiSzerelmesGUID))
        {
            if (eEventStatus == EVENT_NOT_STARTED)
                pSzerelmes->ForcedDespawn();
        }
        else
        {
            if (eEventStatus == EVENT_STARTED)
                ResetEvent();
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

bool GossipHello_npc_karlek(Player *player, Creature *pCreature)
{
    player->ADD_GOSSIP_ITEM(0, "Je suis pret ! Envoyez moi dans l'arene !", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
    player->ADD_GOSSIP_ITEM(0, "Non merci, je ne veut pas combattre.",   GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    player->SEND_GOSSIP_MENU(npc_karlek_HELLO, pCreature->GetObjectGuid());
    return true;
}

bool GossipSelect_npc_karlek(Player* player, Creature* pCreature, uint32 sender, uint32 action)
{
    ArenaBossSzerelmesStatus eEventStatus; // Penser à déclarer la variable

    // Récupérer l'état de la variable comme elle est dans l'IA (npc_karlekAI)
    npc_karlekAI* pKarlekAI = dynamic_cast<npc_karlekAI*>(pCreature->AI());
    if (pKarlekAI)
    {
        eEventStatus = pKarlekAI->GetEventStatus(); // GetEventStatus c'est la fonction qu'il y a dans l'IA, et qui donne le eEventStatus
    }
    if (sender != GOSSIP_SENDER_MAIN)
        return false;

    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF:
        {
            if (eEventStatus == EVENT_NOT_STARTED)
            {
                char sMessage[200];
                sprintf(sMessage, "Bon courage %s !", player->GetName());
                pCreature->MonsterSay(sMessage, 0, 0);
                if (pKarlekAI)
                    pKarlekAI->StartEvent(player);
                SHOW_GOSSIP(npc_karlek_OK);
                sprintf(sMessage, "Force et Honneur !");
                pCreature->MonsterYell(sMessage, 0, 0);
            }
            else
            {
                char sMessage[200];
                sprintf(sMessage, "%s, un Combat est actuellement en cours, Veuillez patientez!", player->GetName());
                pCreature->MonsterSay(sMessage, 0, 0);
                SHOW_GOSSIP(npc_karlek_ERROR);
            }

        }
        break;
        case GOSSIP_ACTION_INFO_DEF+1:
        {
            char sMessage[200];
            sprintf(sMessage, "Revenez me voir lorsque vous serez pret %s .", player->GetName());
            pCreature->MonsterSay(sMessage, 0, 0);

            SHOW_GOSSIP(npc_karlek_OK);
            return true;
        }
        break;
    }
    SHOW_GOSSIP(npc_karlek_ERROR);
    return false;
}

CreatureAI* GetAI_npc_Karlek(Creature* pCreature)
{
    return new npc_karlekAI(pCreature);
}

/*#########################
## npc_Laska
##########################*/

enum
{
    npc_laska_HELLO = 1,
    npc_laska_ERROR = 1,
    npc_laska_OK    = 1
};

bool GossipHello_npc_laska(Player *player, Creature *pCreature)
{
    player->ADD_GOSSIP_ITEM(0, "Envoyez moi hors de l'arene Svp !", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
    player->SEND_GOSSIP_MENU(npc_laska_HELLO, pCreature->GetObjectGuid());
    return true;
}

bool GossipSelect_npc_laska(Player *player, Creature *pCreature, uint32 sender, uint32 action)
{
    ArenaBossSzerelmesStatus eEventStatus;
    npc_karlekAI* pKarlekAI = dynamic_cast<npc_karlekAI*>(pCreature->AI());
    if (pKarlekAI)
        eEventStatus = pKarlekAI->GetEventStatus();
    if (sender != GOSSIP_SENDER_MAIN)
        return false;
    if (GOSSIP_ACTION_INFO_DEF)
    {
        if (eEventStatus == EVENT_NOT_STARTED)
        {
            char sMessage[200];
            sprintf(sMessage, "A bientot !");
            pCreature->MonsterSay(sMessage, 0, 0);
            player->TeleportTo(1, 2202.89f, -4784.48f, 65.18f, 2.14f);
        }
        else
        {
            char sMessage[200];
            sprintf(sMessage, "Vous n\'etes qu'un lache, Nul ne serait quitter le combat comme cela !");
            pCreature->MonsterSay(sMessage, 0, 0);
        }
    }
    SHOW_GOSSIP(npc_laska_ERROR);
    return false;
}

void AddSC_boss_arena_hardog()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "arena_szerelmes";
    newscript->GetAI = &GetAI_arena_szerelmes;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_karlek";
    newscript->pGossipHello   = &GossipHello_npc_karlek;
    newscript->pGossipSelect  = &GossipSelect_npc_karlek;
    newscript->GetAI = &GetAI_npc_Karlek;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_laska";
    newscript->pGossipHello   = &GossipHello_npc_laska;
    newscript->pGossipSelect  = &GossipSelect_npc_laska;
    newscript->RegisterSelf();
};

