UPDATE characters SET playerFlags = playerFlags & ~0x01000000;

TRUNCATE TABLE character_battle_pet_journal;
TRUNCATE TABLE character_battle_pet;