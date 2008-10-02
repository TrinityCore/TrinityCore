DELETE FROM spell_affect WHERE entry = 16089;
INSERT INTO spell_affect (entry,effectId,SpellFamily,SpellFamilyMask,Charges) VALUES
(16089,0,0,0x00000004D3300407,0);

DELETE FROM spell_affect WHERE entry = 16166;
INSERT INTO spell_affect (entry,effectId,SpellFamily,SpellFamilyMask,Charges) VALUES
(16166,0,0,0x0000000090100003,0),
(16166,1,0,0x0000000090100003,0);


