-- Kill xp exploit, mobs spawned by portal keepers don't gives xp on retail. (ie mobs 30662, 30664)
UPDATE `creature_template` SET `flags_extra`= `flags_extra`|64 WHERE `entry` IN (
-- NORMAL
30661, --  CREATURE_AZURE_INVADER_1
30961, -- CREATURE_AZURE_INVADER_2 
30662, -- CREATURE_AZURE_SPELLBREAKER_1 
30962, -- CREATURE_AZURE_SPELLBREAKER_2 
30663, -- CREATURE_AZURE_BINDER_1 
30918, -- CREATURE_AZURE_BINDER_2 
30664, -- CREATURE_AZURE_MAGE_SLAYER_1 
30963, -- CREATURE_AZURE_MAGE_SLAYER_2
-- HEROIC:
31487, -- Azure Invader
31494, -- Azure Spellbreaker
31483, -- Azure Binder
31497, -- Azure Mage Slayer
31484, -- Azure Binder
31488, -- Azure Invader
31495, -- Azure Spellbreaker
31498  -- Azure Mage Slayer
); 
