DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) AND `SourceEntry` IN (13671,13625,13670,13669,13666);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) AND `SourceEntry` IN (13676,13673,13674,13675,13677);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
-- Alliance
(19,0,13671,0,8,13835,0,0,0, '', NULL), -- Training In The Field - Mastery Of The Shield-Breaker
(20,0,13671,0,8,13835,0,0,0, '', NULL),
(19,0,13671,0,8,13837,0,0,0, '', NULL), -- Training In The Field - Mastery Of The Charge
(20,0,13671,0,8,13837,0,0,0, '', NULL),
(19,0,13671,0,8,13828,0,0,0, '', NULL), -- Training In The Field - Mastery Of Melee
(20,0,13671,0,8,13828,0,0,0, '', NULL),
(19,0,13625,0,8,13835,0,0,0, '', NULL), -- Learning The Reins - Mastery Of The Shield-Breaker
(20,0,13625,0,8,13835,0,0,0, '', NULL),
(19,0,13625,0,8,13837,0,0,0, '', NULL), -- Learning The Reins - Mastery Of The Charge
(20,0,13625,0,8,13837,0,0,0, '', NULL),
(19,0,13625,0,8,13828,0,0,0, '', NULL), -- Learning The Reins - Mastery Of Melee
(20,0,13625,0,8,13828,0,0,0, '', NULL),
(19,0,13670,0,8,13835,0,0,0, '', NULL), -- The Edge Of Winter - Mastery Of The Shield-Breaker
(20,0,13670,0,8,13835,0,0,0, '', NULL),
(19,0,13670,0,8,13837,0,0,0, '', NULL), -- The Edge Of Winter - Mastery Of The Charge
(20,0,13670,0,8,13837,0,0,0, '', NULL),
(19,0,13670,0,8,13828,0,0,0, '', NULL), -- The Edge Of Winter - Mastery Of Melee
(20,0,13670,0,8,13828,0,0,0, '', NULL),
(19,0,13669,0,8,13835,0,0,0, '', NULL), -- A Worthy Weapon - Mastery Of The Shield-Breaker
(20,0,13669,0,8,13835,0,0,0, '', NULL),
(19,0,13669,0,8,13837,0,0,0, '', NULL), -- A Worthy Weapon - Mastery Of The Charge
(20,0,13669,0,8,13837,0,0,0, '', NULL),
(19,0,13669,0,8,13828,0,0,0, '', NULL), -- A Worthy Weapon - Mastery Of Melee
(20,0,13669,0,8,13828,0,0,0, '', NULL),
(19,0,13666,0,8,13835,0,0,0, '', NULL), -- A Blade Fit For A Champion - Mastery Of The Shield-Breaker
(20,0,13666,0,8,13835,0,0,0, '', NULL),
(19,0,13666,0,8,13837,0,0,0, '', NULL), -- A Blade Fit For A Champion - Mastery Of The Charge
(20,0,13666,0,8,13837,0,0,0, '', NULL),
(19,0,13666,0,8,13828,0,0,0, '', NULL), -- A Blade Fit For A Champion - Mastery Of Melee
(20,0,13666,0,8,13828,0,0,0, '', NULL),
-- Horde
(19,0,13676,0,8,13838,0,0,0, '', NULL), -- Training In The Field - Mastery Of The Shield-Breaker
(20,0,13676,0,8,13838,0,0,0, '', NULL),
(19,0,13676,0,8,13839,0,0,0, '', NULL), -- Training In The Field - Mastery Of The Charge
(20,0,13676,0,8,13839,0,0,0, '', NULL),
(19,0,13676,0,8,13829,0,0,0, '', NULL), -- Training In The Field - Mastery Of Melee
(20,0,13676,0,8,13829,0,0,0, '', NULL),
(19,0,13677,0,8,13838,0,0,0, '', NULL), -- Learning The Reins - Mastery Of The Shield-Breaker
(20,0,13677,0,8,13838,0,0,0, '', NULL),
(19,0,13677,0,8,13839,0,0,0, '', NULL), -- Learning The Reins - Mastery Of The Charge
(20,0,13677,0,8,13839,0,0,0, '', NULL),
(19,0,13677,0,8,13829,0,0,0, '', NULL), -- Learning The Reins - Mastery Of Melee
(20,0,13677,0,8,13829,0,0,0, '', NULL),
(19,0,13675,0,8,13838,0,0,0, '', NULL), -- The Edge Of Winter - Mastery Of The Shield-Breaker
(20,0,13675,0,8,13838,0,0,0, '', NULL),
(19,0,13675,0,8,13839,0,0,0, '', NULL), -- The Edge Of Winter - Mastery Of The Charge
(20,0,13675,0,8,13839,0,0,0, '', NULL),
(19,0,13675,0,8,13829,0,0,0, '', NULL), -- The Edge Of Winter - Mastery Of Melee
(20,0,13675,0,8,13829,0,0,0, '', NULL),
(19,0,13674,0,8,13838,0,0,0, '', NULL), -- A Worthy Weapon - Mastery Of The Shield-Breaker
(20,0,13674,0,8,13838,0,0,0, '', NULL),
(19,0,13674,0,8,13839,0,0,0, '', NULL), -- A Worthy Weapon - Mastery Of The Charge
(20,0,13674,0,8,13839,0,0,0, '', NULL),
(19,0,13674,0,8,13829,0,0,0, '', NULL), -- A Worthy Weapon - Mastery Of Melee
(20,0,13674,0,8,13829,0,0,0, '', NULL),
(19,0,13673,0,8,13838,0,0,0, '', NULL), -- A Blade Fit For A Champion - Mastery Of The Shield-Breaker
(20,0,13673,0,8,13838,0,0,0, '', NULL),
(19,0,13673,0,8,13839,0,0,0, '', NULL), -- A Blade Fit For A Champion - Mastery Of The Charge
(20,0,13673,0,8,13839,0,0,0, '', NULL),
(19,0,13673,0,8,13829,0,0,0, '', NULL), -- A Blade Fit For A Champion - Mastery Of Melee
(20,0,13673,0,8,13829,0,0,0, '', NULL);
