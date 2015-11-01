//#include "ScriptPCH.h"

class summon : public ItemScript
{
        public:
                summon() : ItemScript("summon")
                {
                }
                bool OnUse(Player* pPlayer, Item* pItem, SpellCastTargets const& /*targets*/)
                {
   uint32 sSpell = 18282; //Icerune Visual Spell when used
   if (pPlayer->IsInCombat())
   {
        pPlayer->GetSession()->SendNotification("You are in combat.");
   }

   else if (pPlayer->isMoving())
   {
        pPlayer->GetSession()->SendNotification("You can not do that while moving.");
   }

   else if (pPlayer->FindNearestCreature(80410, 40) || pPlayer->FindNearestCreature(100000, 8))
   {
        pPlayer->GetSession()->SendNotification("Teleportercan not be summoned because another Teleporter is within range.");
   }

   else
   {
        float x, y, z, o = pPlayer->GetOrientation();

        if (o >= 3.141592)
         o = o - 3.141592;
        else
         o = o + 3.141592;
        pPlayer->GetClosePoint(x, y, z, pPlayer->GetObjectSize());
        Creature* pCreature = pPlayer->SummonCreature(100000, x, y, z+2.2, o, TEMPSUMMON_TIMED_DESPAWN, 50000);
        pCreature->CastSpell(pCreature, 63660);
        return false;
   }
  return false;
                }
};
void AddSC_summon()
{
        new summon();
}