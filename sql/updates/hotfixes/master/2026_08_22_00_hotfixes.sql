DELETE FROM `hotfix_data` WHERE `TableHash`=0xC68BE365 AND `RecordId` IN (SELECT `RecordId` FROM `hotfix_blob` WHERE `TableHash`=0xC68BE365); -- CooldownSet
DELETE FROM `hotfix_data` WHERE `TableHash`=0x4BF2FC04 AND `RecordId` IN (SELECT `RecordId` FROM `hotfix_blob` WHERE `TableHash`=0x4BF2FC04); -- CooldownSetSpell
DELETE FROM `hotfix_data` WHERE `TableHash`=0x284224BE AND `RecordId` IN (SELECT `RecordId` FROM `hotfix_blob` WHERE `TableHash`=0x284224BE); -- CraftingQualityAtlasSet
DELETE FROM `hotfix_data` WHERE `TableHash`=0x803704B6 AND `RecordId` IN (SELECT `RecordId` FROM `hotfix_blob` WHERE `TableHash`=0x803704B6); -- EdgeGlowEffect
DELETE FROM `hotfix_data` WHERE `TableHash`=0x6FF1C5BA AND `RecordId` IN (SELECT `RecordId` FROM `hotfix_blob` WHERE `TableHash`=0x6FF1C5BA); -- ExteriorComponent
DELETE FROM `hotfix_data` WHERE `TableHash`=0x137145D0 AND `RecordId` IN (SELECT `RecordId` FROM `hotfix_blob` WHERE `TableHash`=0x137145D0); -- HouseDecor
DELETE FROM `hotfix_data` WHERE `TableHash`=0xBBA2E8F8 AND `RecordId` IN (SELECT `RecordId` FROM `hotfix_blob` WHERE `TableHash`=0xBBA2E8F8); -- HouseRoom
DELETE FROM `hotfix_data` WHERE `TableHash`=0xF5D19E56 AND `RecordId` IN (SELECT `RecordId` FROM `hotfix_blob` WHERE `TableHash`=0xF5D19E56); -- ItemConversion
DELETE FROM `hotfix_data` WHERE `TableHash`=0x192B936F AND `RecordId` IN (SELECT `RecordId` FROM `hotfix_blob` WHERE `TableHash`=0x192B936F); -- PlayerCompanionInfo
DELETE FROM `hotfix_data` WHERE `TableHash`=0xB33F3964 AND `RecordId` IN (SELECT `RecordId` FROM `hotfix_blob` WHERE `TableHash`=0xB33F3964); -- ScreenEffect
DELETE FROM `hotfix_data` WHERE `TableHash`=0x1EF95B83 AND `RecordId` IN (SELECT `RecordId` FROM `hotfix_blob` WHERE `TableHash`=0x1EF95B83); -- SeamlessSite
DELETE FROM `hotfix_data` WHERE `TableHash`=0xF8685781 AND `RecordId` IN (SELECT `RecordId` FROM `hotfix_blob` WHERE `TableHash`=0xF8685781); -- SpellActivationOverlay

DELETE FROM `hotfix_blob` WHERE `TableHash`=0xC68BE365; -- CooldownSet
DELETE FROM `hotfix_blob` WHERE `TableHash`=0x4BF2FC04; -- CooldownSetSpell
DELETE FROM `hotfix_blob` WHERE `TableHash`=0x284224BE; -- CraftingQualityAtlasSet
DELETE FROM `hotfix_blob` WHERE `TableHash`=0x803704B6; -- EdgeGlowEffect
DELETE FROM `hotfix_blob` WHERE `TableHash`=0x6FF1C5BA; -- ExteriorComponent
DELETE FROM `hotfix_blob` WHERE `TableHash`=0x137145D0; -- HouseDecor
DELETE FROM `hotfix_blob` WHERE `TableHash`=0xBBA2E8F8; -- HouseRoom
DELETE FROM `hotfix_blob` WHERE `TableHash`=0xF5D19E56; -- ItemConversion
DELETE FROM `hotfix_blob` WHERE `TableHash`=0x192B936F; -- PlayerCompanionInfo
DELETE FROM `hotfix_blob` WHERE `TableHash`=0xB33F3964; -- ScreenEffect
DELETE FROM `hotfix_blob` WHERE `TableHash`=0x1EF95B83; -- SeamlessSite
DELETE FROM `hotfix_blob` WHERE `TableHash`=0xF8685781; -- SpellActivationOverlay
