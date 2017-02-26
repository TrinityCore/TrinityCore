#pragma once

using namespace std;

namespace ai
{
    class MockedTargets
    {
	public:
		static Unit* GetPartyMember() { return (Unit*)1; }
		static Unit* GetCurrentTarget()  { return (Unit*)7; }
		static Player* GetSelf() { return (Player*)9; }
		static Unit* GetPet() { return (Unit*)10; }
		static Player* GetMaster() { return (Player*)2; }
        static Player* GetTargetForDps() { return (Player*)3; }
        static Player* GetTargetForTank() { return (Player*)4; }
        static Player* GetCc() { return (Player*)12; }
		static Player* GetLineTarget() { return (Player*)14; }
		static Unit* GetLeastHpPartyMember() { return (Unit*)16; }
		static Unit* GetRtiTarget() { return (Unit*)17; }
		static Unit* GetDuelTarget() { return (Unit*)18; }
		static Unit* GetGridTarget() { return (Unit*)19; }
		static Unit* GetEnemyPlayer() { return (Unit*)20; }
		static Unit* GetAttackerWithoutAura() { return (Unit*)21; }
		static Unit* GetEnemyHealer() { return (Unit*)22; }

        static void Append(string &buffer, Unit* unit)
        {
            if (unit == GetPartyMember())
                buffer.append("P");
            if (unit == GetCurrentTarget())
                buffer.append("T");
            if (unit == GetSelf())
                buffer.append("S");
            if (unit == GetPet())
                buffer.append("Pet");
            if (unit == GetMaster())
                buffer.append("M");
            if (unit == GetTargetForDps())
                buffer.append("Dps");
            if (unit == GetTargetForTank())
                buffer.append("Tank");
            if (unit == GetCc())
                buffer.append("Cc");
            if (unit == GetLineTarget())
                buffer.append("Line");
            if (unit == GetRtiTarget())
                buffer.append("Rti");
            if (unit == GetDuelTarget())
                buffer.append("Duel");
            if (unit == GetGridTarget())
                buffer.append("Grind");
            if (unit == GetEnemyPlayer())
                buffer.append("Enemy");
            if (unit == GetAttackerWithoutAura())
                buffer.append("A");
            if (unit == GetEnemyHealer())
                buffer.append("H");
        }
   };

}
