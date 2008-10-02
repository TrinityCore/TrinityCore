DELETE FROM spell_proc_event WHERE entry = 13743 OR entry = 13875;
DELETE FROM spell_proc_event WHERE entry = 14076 OR entry = 14094;

UPDATE spell_proc_event SET Category = 0, SkillId = 0 WHERE entry = 12797 OR entry = 12799 OR entry = 12800;
UPDATE spell_proc_event SET Category = 0 WHERE entry = 13754 OR entry = 13867;
UPDATE spell_proc_event SET Category = 0 WHERE entry = 40458;

UPDATE spell_proc_event SET SkillId = 0 WHERE entry = 16850 OR entry = 16923 OR entry = 16924;
UPDATE spell_proc_event SET SkillId = 0 WHERE entry = 17793 OR entry = 17796 OR entry = 17801 OR entry = 17802 OR entry = 17803;
UPDATE spell_proc_event SET SkillId = 0, SchoolMask = 0 WHERE entry = 23721;
UPDATE spell_proc_event SET SkillId = 0, SchoolMask = 0 WHERE entry = 28809;
UPDATE spell_proc_event SET SkillId = 0, SchoolMask = 0 WHERE entry = 28823;
UPDATE spell_proc_event SET SkillId = 0 WHERE entry = 23695;

UPDATE spell_proc_event SET SchoolMask = 0, SpellFamilyMask = 0x8000000060 WHERE entry = 18073 OR entry = 18096;
UPDATE spell_proc_event SET SchoolMask = 0 WHERE entry = 19407 OR entry = 19412 OR entry = 19413 OR entry = 19414 OR entry = 19415;
UPDATE spell_proc_event SET SchoolMask = 0 WHERE entry = 20234 OR entry = 20235;
UPDATE spell_proc_event SET SchoolMask = 0 WHERE entry = 23551 OR entry = 23572;
UPDATE spell_proc_event SET SchoolMask = 0 WHERE entry = 38394;