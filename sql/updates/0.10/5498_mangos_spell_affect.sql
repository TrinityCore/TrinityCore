-- Ice Shards
UPDATE spell_affect SET SpellFamilyMask = SpellFamilyMask | 0x20000 WHERE (entry = 11207) OR (entry = 12672) OR (entry = 15047) OR (entry = 15052) OR (entry = 15053);
-- Piercing Ice
UPDATE spell_affect SET SpellFamilyMask = SpellFamilyMask | 0x20000 WHERE ((entry = 11151) OR (entry = 12952) OR (entry = 12953) OR (entry = 12954) OR (entry = 12957)) AND (effectId = 0);
-- Arctic Reach
UPDATE spell_affect SET SpellFamilyMask = SpellFamilyMask | 0x20000 WHERE ((entry = 16757) OR (entry = 16758)) AND (effectId = 0);
-- Frost Channeling
UPDATE spell_affect SET SpellFamilyMask = SpellFamilyMask | 0x20000 WHERE ((entry = 11160) OR (entry = 12518) OR (entry = 12519)) AND (effectId = 0);