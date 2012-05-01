#include "ScriptPCH.h"

///////////////////////////////////////////////////////////////////////
///////////////////////      CONFIG      /////////////////////////////
/////////////////////////////////////////////////////////////////////

float Version = 2.50f;                            //Don't touch this.
bool PvPSystemEnabled = true;                    //Set to false if you want to disable the PvP System
bool OnlyInBattlegrounds = false;                //Set to true if you want to enable this only in battlegrounds.
bool LooseTokenOnPvPDeath = false;                //Set to true if you want the victim to loose tokens when the victim dies.
int32 AmountOfItemsYouWantTheVictimToLoose = 0; //Amount of items you want the victim to loose when victim dies.
bool AddTokenOnPvPKill = true;                    //Set to false if you don't want the killer to be rewarded.
int32 ItemReward = 44751;                        //The ItemID of the reward.
int32 AmountOfRewardsOnKillStreak[12] = { 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3 }; //With how many items you want to reward the killer when he slays the victim.
int32 HowManyTimesYouWantTheKillerToGetAwardedForKillingTheSameVictim = 25; //Name speaks for It self.
const int32 KillerStreak15 = 2;
const int32 KillerStreak20 = 3;
const int32 KillerStreak30 = 5;
const int32 KillerStreak40 = 7;
const int32 KillerStreak50 = 10;
const int32 KillerStreak60 = 15;
const int32 KillerStreak70 = 20;
const int32 KillerStreak80 = 25;
const int32 KillerStreak90 = 30;
const int32 KillerStreak100 = 35;
const int32 KillerStreak110 = 40;
const int32 KillerStreak120 = 50;
int32 KillStreaks[12] = { KillerStreak15, KillerStreak20, KillerStreak30, KillerStreak40, KillerStreak50, KillerStreak60, KillerStreak70, KillerStreak80, KillerStreak90, KillerStreak100, KillerStreak110, KillerStreak120 };
///////////////////////////////////////////////////////////////////
///////////////////////      END      ////////////////////////////
/////////////////////////////////////////////////////////////////


struct SystemInfo
{
    uint32 KillStreak;
    uint32 LastGUIDKill;
    uint8 KillCount;
};

static std::map<uint32, SystemInfo> KillingStreak;

class System_OnPVPKill : public PlayerScript
{
public:
    System_OnPVPKill() : PlayerScript("System_OnPVPKill") {}

    void OnPVPKill(Player *pKiller, Player *pVictim)
    {
        if(PvPSystemEnabled == false)
        {
            return;
        }
        else if(PvPSystemEnabled == true)
        {
            uint32 kGUID;
            uint32 vGUID;
            char msg[500];
            kGUID = pKiller->GetGUID();
            vGUID = pVictim->GetGUID();
            if(kGUID == vGUID)
            {
                return;
            }
            if(KillingStreak[kGUID].LastGUIDKill == vGUID)
            {
                KillingStreak[kGUID].KillCount++;
                KillingStreak[vGUID].KillCount = 1;
                pKiller->AddItem(ItemReward, 1);
                if(LooseTokenOnPvPDeath == true)
                    pVictim->DestroyItemCount(ItemReward, AmountOfItemsYouWantTheVictimToLoose, true, false);
            }
            if(KillingStreak[kGUID].LastGUIDKill != vGUID)
            {
                KillingStreak[kGUID].KillCount = 1;
                KillingStreak[vGUID].KillCount = 1;
            }
            if(KillingStreak[kGUID].KillCount == HowManyTimesYouWantTheKillerToGetAwardedForKillingTheSameVictim)
            {
                return;
            }
            if(OnlyInBattlegrounds == true)
            {
                if(!pKiller->GetMap()->IsBattleground())
                    return;
            }

            KillingStreak[kGUID].KillStreak++;
            KillingStreak[vGUID].KillStreak = 0;
            KillingStreak[kGUID].LastGUIDKill = vGUID;
            KillingStreak[vGUID].LastGUIDKill = 0;
            if(AddTokenOnPvPKill == true)
                pKiller->AddItem(ItemReward, 1);
            if(LooseTokenOnPvPDeath == true)
                pVictim->DestroyItemCount(ItemReward, AmountOfItemsYouWantTheVictimToLoose, true, false);

            switch(KillingStreak[kGUID].KillStreak)
            {
            case 22:
                int RandomSpell;
                switch(urand(1, 14))
                {
                case 1:
                    RandomSpell = 42828;
                    break;
                case 2:
                    RandomSpell = 11009;
                    break;
                case 3:
                    RandomSpell = 72726;
                    break;
                case 4:
                    RandomSpell = 19883;
                    break;
                case 5:
                    RandomSpell = 41969;
                    break;
                case 6:
                    RandomSpell = 43776;
                    break;
                case 7:
                    RandomSpell = 63660;
                    break;
                case 8:
                    RandomSpell = 51929;
                    break;
                case 9:
                    RandomSpell = 62398;
                    break;
                case 10:
                    RandomSpell = 60342;
                    break;
                case 11:
                    RandomSpell = 47335;
                    break;
                case 12:
                    RandomSpell = 69861;
                    break;
                case 13:
                    RandomSpell = 70571;
                    break;
                case 14:
                    RandomSpell = 11010;
                    break;
                }
                pKiller->CastSpell(pKiller,RandomSpell,true);
                break;
            case KillerStreak15:
                sprintf(msg, "PvP-система]: РАНГ(1) остерегайтесь встречи с %s, он(а) безжалостно уничтожил(а) %s, и пополнил(а) свою коллекцию 2м скальпом...", pKiller->GetName(), pVictim->GetName(), KillStreaks[1]);
                sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
                pKiller->AddItem(ItemReward, AmountOfRewardsOnKillStreak[1]);
                break;
            case KillerStreak20:
                sprintf(msg, "PvP-система]: РАНГ(2) остерегайтесь встречи с %s, он(а) безжалостно уничтожил(а) %s, и пополнил(а) свою коллекцию 3м скальпом...", pKiller->GetName(), pVictim->GetName(), KillStreaks[2]);
                sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
                pKiller->AddItem(ItemReward, AmountOfRewardsOnKillStreak[1]);
                break;
            case KillerStreak30:
                sprintf(msg, "[PvP System]: РАНГ(3) остерегайтесь встречи с %s, он(а) безжалостно уничтожил(а) %s, и пополнил(а) свою коллекцию 5м скальпом...", pKiller->GetName(), pVictim->GetName(), KillStreaks[3]);
                sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
                pKiller->AddItem(ItemReward, AmountOfRewardsOnKillStreak[1]);
                break;
            case KillerStreak40:
                sprintf(msg, "[PvP System]: РАНГ(4) остерегайтесь встречи с %s, он(а) безжалостно уничтожил(а) %s, и пополнил(а) свою коллекцию 7м скальпом...", pKiller->GetName(), pVictim->GetName(), KillStreaks[4]);
                sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
                pKiller->AddItem(ItemReward, AmountOfRewardsOnKillStreak[2]);
                break;
            case KillerStreak50:
                sprintf(msg, "[PvP System]: РАНГ(5) остерегайтесь встречи с %s, он(а) безжалостно уничтожил(а) %s, и пополнил(а) свою коллекцию 10м скальпом...", pKiller->GetName(), pVictim->GetName(), KillStreaks[5]);
                sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
                pKiller->AddItem(ItemReward, AmountOfRewardsOnKillStreak[2]);
                break;
            case KillerStreak60:
                sprintf(msg, "[PvP System]: РАНГ(6) остерегайтесь встречи с %s, он(а) безжалостно уничтожил(а) %s, и пополнил(а) свою коллекцию 15м скальпом...", pKiller->GetName(), pVictim->GetName(), KillStreaks[6]);
                sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
                pKiller->AddItem(ItemReward, AmountOfRewardsOnKillStreak[2]);
                break;
            case KillerStreak70:
                sprintf(msg, "[PvP System]: РАНГ(7) остерегайтесь встречи с %s, он(а) безжалостно уничтожил(а) %s, и пополнил(а) свою коллекцию 20м скальпом...", pKiller->GetName(), pVictim->GetName(), KillStreaks[7]);
                sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
                pKiller->AddItem(ItemReward, AmountOfRewardsOnKillStreak[3]);
                break;
            case KillerStreak80:
                sprintf(msg, "[PvP System]: РАНГ(8) остерегайтесь встречи с %s, он(а) безжалостно уничтожил(а) %s, и пополнил(а) свою коллекцию 25м скальпом...", pKiller->GetName(), pVictim->GetName(), KillStreaks[8]);
                sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
                pKiller->AddItem(ItemReward, AmountOfRewardsOnKillStreak[3]);
                break;
            case KillerStreak90:
                sprintf(msg, "[PvP System]: РАНГ(9) остерегайтесь встречи с %s, он(а) безжалостно уничтожил(а) %s, и пополнил(а) свою коллекцию 30м скальпом...", pKiller->GetName(), pVictim->GetName(), KillStreaks[9]);
                sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
                pKiller->AddItem(ItemReward, AmountOfRewardsOnKillStreak[3]);
                break;
            case KillerStreak100:
                sprintf(msg, "[PvP System]: РАНГ(10) остерегайтесь встречи с %s, он(а) безжалостно уничтожил(а) %s, и пополнил(а) свою коллекцию 35м скальпом...", pKiller->GetName(), pVictim->GetName(), KillStreaks[10]);
                sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
                pKiller->AddItem(ItemReward, AmountOfRewardsOnKillStreak[4]);
                break;
            case KillerStreak110:
                sprintf(msg, "[PvP System]: РАНГ(11) остерегайтесь встречи с %s, он(а) безжалостно уничтожил(а) %s, и пополнил(а) свою коллекцию 40м скальпом...", pKiller->GetName(), pVictim->GetName(), KillStreaks[11]);
                sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
                pKiller->AddItem(ItemReward, AmountOfRewardsOnKillStreak[4]);
                break;
            case KillerStreak120:
                sprintf(msg, "[PvP System]: РАНГ(12) остерегайтесь встречи с %s, он(а) безжалостно уничтожил(а) %s, и пополнил(а) свою коллекцию 50м скальпом...", pKiller->GetName(), pVictim->GetName(), KillStreaks[12]);
                sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
                pKiller->AddItem(ItemReward, AmountOfRewardsOnKillStreak[5]);
                break;
            }
        }
    }
};

void AddSC_System_OnPVPKill()
{
    new System_OnPVPKill();
}