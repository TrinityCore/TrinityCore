UPDATE `creature` SET `id`= 54657 WHERE `guid`= 3990002;
UPDATE `creature` SET `id`= 54658 WHERE `guid`= 3990003;
UPDATE `creature` SET `id`= 54659 WHERE `guid`= 3990004;

DELETE FROM `npc_vendor` WHERE `entry` IN (54657, 54658, 54659);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(54657, 1, 73701, 0, 3712, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Ornamented Chestguard
(54657, 2, 73742, 0, 3705, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Dreadplate Chestpiece
(54657, 3, 73718, 0, 3731, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Chain Armor
(54657, 4, 73708, 0, 3722, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Scaled Chestpiece
(54657, 5, 73682, 0, 3772, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Leather Tunic
(54657, 6, 73665, 0, 3748, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Mail Armor
(54657, 7, 73670, 0, 3743, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Linked Armor
(54657, 8, 73675, 0, 3738, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Ringmail Armor
(54657, 9, 73655, 0, 3717, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Plate Chestpiece
(54657, 10, 73743, 0, 3779, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Treads of Meditation
(54657, 11, 73744, 0, 3778, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Treads of Alacrity
(54657, 12, 73745, 0, 3777, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Treads of Cruelty
(54657, 13, 73703, 0, 3710, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Greaves of Alacrity
(54657, 14, 73726, 0, 3759, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Footguards of Alacrity
(54657, 15, 73732, 0, 3758, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Footguards of Meditation
(54657, 16, 73719, 0, 3730, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Sabatons of Alacrity
(54657, 17, 73720, 0, 3729, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Sabatons of Cruelty
(54657, 18, 73683, 0, 3771, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Boots of Alacrity
(54657, 19, 73684, 0, 3770, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Boots of Cruelty
(54657, 20, 73702, 0, 3711, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Greaves of Meditation
(54657, 21, 73695, 0, 3727, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Warboots of Alacrity
(54657, 22, 73696, 0, 3728, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Warboots of Cruelty
(54657, 23, 73676, 0, 3737, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Sabatons of Meditation
(54657, 24, 73677, 0, 3736, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Sabatons of Alacrity
(54657, 25, 73700, 0, 3713, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Ornamented Gloves
(54657, 26, 73737, 0, 3753, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Dragonhide Gloves
(54657, 27, 73713, 0, 3780, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Silk Handguards
(54657, 28, 73741, 0, 3706, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Dreadplate Gauntlets
(54657, 29, 73725, 0, 3765, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Wyrmhide Gloves
(54657, 30, 73717, 0, 3732, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Chain Gauntlets
(54657, 31, 73731, 0, 3760, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Kodohide Gloves
(54657, 32, 73707, 0, 3723, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Scaled Gauntlets
(54657, 33, 73681, 0, 3773, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Leather Gloves
(54657, 34, 73660, 0, 3795, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Felweave Handguards
(54657, 35, 73664, 0, 3749, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Mail Gauntlets
(54657, 36, 73689, 0, 3790, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Satin Gloves
(54657, 37, 73669, 0, 3744, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Linked Gauntlets
(54657, 38, 73694, 0, 3785, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Mooncloth Gloves
(54657, 39, 73654, 0, 3718, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Plate Gauntlets
(54657, 40, 73674, 0, 3739, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Ringmail Gauntlets
(54657, 41, 73736, 0, 3754, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Dragonhide Helm
(54657, 42, 73699, 0, 3714, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Ornamented Headcover
(54657, 43, 73712, 0, 3781, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Silk Cowl
(54657, 44, 73724, 0, 3766, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Wyrmhide Helm
(54657, 45, 73740, 0, 3707, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Dreadplate Helm
(54657, 46, 73716, 0, 3733, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Chain Helm
(54657, 47, 73730, 0, 3761, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Kodohide Helm
(54657, 48, 73706, 0, 3724, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Scaled Helm
(54657, 49, 73680, 0, 3774, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Leather Helm
(54657, 50, 73659, 0, 3796, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Felweave Cowl
(54657, 51, 73663, 0, 3750, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Mail Helm
(54657, 52, 73688, 0, 3791, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Satin Hood
(54657, 53, 73668, 0, 3745, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Linked Helm
(54657, 54, 73693, 0, 3786, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Mooncloth Helm
(54657, 55, 73653, 0, 3719, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Plate Helm
(54657, 56, 73673, 0, 3740, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Ringmail Helm
(54657, 57, 73698, 0, 3715, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Ornamented Legplates
(54657, 58, 73735, 0, 3755, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Dragonhide Legguards
(54657, 59, 73711, 0, 3782, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Silk Trousers
(54657, 60, 73723, 0, 3767, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Wyrmhide Legguards
(54657, 61, 73715, 0, 3734, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Chain Leggings
(54657, 62, 73729, 0, 3762, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Kodohide Legguards
(54657, 63, 73739, 0, 3708, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Dreadplate Legguards
(54657, 64, 73705, 0, 3725, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Scaled Legguards
(54657, 65, 73662, 0, 3751, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Mail Leggings
(54657, 66, 73687, 0, 3792, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Satin Leggings
(54657, 67, 73667, 0, 3746, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Linked Leggings
(54657, 68, 73692, 0, 3787, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Mooncloth Leggings
(54657, 69, 73672, 0, 3741, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Ringmail Leggings
(54657, 70, 73652, 0, 3720, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Plate Legguards
(54657, 71, 73658, 0, 3797, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Felweave Trousers
(54657, 72, 73679, 0, 3775, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Leather Legguards
(54657, 73, 73734, 0, 3756, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Dragonhide Robes
(54657, 74, 73710, 0, 3783, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Silk Robe
(54657, 75, 73722, 0, 3768, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Wyrmhide Robes
(54657, 76, 73728, 0, 3763, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Kodohide Robes
(54657, 77, 73686, 0, 3793, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Satin Robe
(54657, 78, 73691, 0, 3788, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Mooncloth Robe
(54657, 79, 73657, 0, 3798, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Felweave Raiment
(54657, 80, 73738, 0, 3709, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Dreadplate Shoulders
(54657, 81, 73714, 0, 3735, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Chain Spaulders
(54657, 82, 73704, 0, 3726, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Scaled Shoulders
(54657, 83, 73733, 0, 3757, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Dragonhide Spaulders
(54657, 84, 73721, 0, 3769, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Wyrmhide Spaulders
(54657, 85, 73727, 0, 3764, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Kodohide Spaulders
(54657, 86, 73697, 0, 3716, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Ornamented Spaulders
(54657, 87, 73709, 0, 3784, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Silk Amice
(54657, 88, 73661, 0, 3752, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Mail Spaulders
(54657, 89, 73685, 0, 3794, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Satin Mantle
(54657, 90, 73690, 0, 3789, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Mooncloth Mantle
(54657, 91, 73666, 0, 3747, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Linked Spaulders
(54657, 92, 73671, 0, 3742, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Ringmail Spaulders
(54657, 93, 73651, 0, 3721, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Plate Shoulders
(54657, 94, 73656, 0, 3799, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Felweave Amice
(54657, 95, 73678, 0, 3776, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Leather Spaulders
(54657, 96, 73433, 0, 3655, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Battle Staff
(54657, 97, 73443, 0, 3656, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Bonegrinder
(54657, 98, 73423, 0, 3657, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Pike
(54657, 99, 73424, 0, 3658, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Energy Staff
(54657, 100, 73429, 0, 3659, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Staff
(54657, 101, 73444, 0, 3660, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Decapitator
(54657, 102, 73442, 0, 3661, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Greatsword
(54657, 103, 73436, 0, 3663, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Endgame
(54657, 104, 73432, 0, 3662, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Reprieve
(54657, 105, 73419, 0, 3664, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Right Render
(54657, 106, 73421, 0, 3665, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Ripper
(54657, 107, 73426, 0, 3666, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Gavel
(54657, 108, 73434, 0, 3667, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Spellblade
(54657, 109, 73428, 0, 3668, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Shiv
(54657, 110, 73418, 0, 3669, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Slasher
(54657, 111, 73420, 0, 3670, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Fleshslicer
(54657, 112, 73437, 0, 3671, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Longbow
(54657, 113, 73417, 0, 3672, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Baton of Light
(54657, 114, 73427, 0, 3673, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Rifle
(54657, 115, 73430, 0, 3674, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Heavy Crossbow
(54657, 116, 73431, 0, 3675, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Touch of Defeat
(54657, 117, 73413, 0, 3676, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Shield Wall
(54657, 118, 73435, 0, 3677, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Barrier
(54657, 119, 73425, 0, 3678, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Redoubt
(54657, 120, 73438, 0, 3679, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Hatchet
(54657, 121, 73412, 0, 3680, 1, 0, 0, 59185), -- Cataclysmic Gladiator's War Edge
(54657, 122, 73439, 0, 3681, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Quickblade
(54657, 123, 73440, 0, 3682, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Pummeler
(54657, 124, 73414, 0, 3683, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Slicer
(54657, 125, 73415, 0, 3684, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Bonecracker
(54657, 126, 73416, 0, 3685, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Hacker
(54657, 127, 73441, 0, 3686, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Cleaver
(54657, 128, 73422, 0, 3687, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Shanker
(54657, 129, 74783, 0, 3695, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Relic of Conquest
(54657, 130, 74784, 0, 3696, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Relic of Salvation
(54657, 131, 74785, 0, 3697, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Relic of Dominance
(54657, 132, 74786, 0, 3698, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Relic of Triumph
(54658, 1, 73462, 0, 3415, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Staff
(54658, 2, 73456, 0, 3415, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Pike
(54658, 3, 73457, 0, 3415, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Energy Staff
(54658, 4, 73475, 0, 3415, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Greatsword
(54658, 5, 73466, 0, 3415, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Battle Staff
(54658, 6, 73476, 0, 3415, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Bonegrinder
(54658, 7, 73477, 0, 3415, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Decapitator
(54658, 8, 73465, 0, 3417, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Reprieve
(54658, 9, 73469, 0, 3417, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Endgame
(54658, 10, 73467, 0, 3416, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Spellblade
(54658, 11, 73452, 0, 3416, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Right Render
(54658, 12, 73454, 0, 3416, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Ripper
(54658, 13, 73459, 0, 3416, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Gavel
(54658, 14, 73461, 0, 3417, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Shiv
(54658, 15, 73451, 0, 3417, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Slasher
(54658, 16, 73453, 0, 3417, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Fleshslicer
(54658, 17, 73470, 0, 3415, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Longbow
(54658, 18, 73464, 0, 3652, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Touch of Defeat
(54658, 19, 73460, 0, 3415, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Rifle
(54658, 20, 73463, 0, 3415, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Heavy Crossbow
(54658, 21, 73450, 0, 3652, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Baton of Light
(54658, 22, 73446, 0, 3417, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Shield Wall
(54658, 23, 73458, 0, 3417, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Redoubt
(54658, 24, 73468, 0, 3417, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Barrier
(54658, 25, 73445, 0, 3652, 1, 0, 0, 59185), -- Cataclysmic Gladiator's War Edge
(54658, 26, 73471, 0, 3652, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Hatchet
(54658, 27, 73455, 0, 3416, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Shanker
(54658, 28, 73447, 0, 3416, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Slicer
(54658, 29, 73473, 0, 3416, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Pummeler
(54658, 30, 73472, 0, 3416, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Quickblade
(54658, 31, 73449, 0, 3416, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Hacker
(54658, 32, 73448, 0, 3416, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Bonecracker
(54658, 33, 73474, 0, 3416, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Cleaver
(54658, 34, 73645, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Necklace of Proficiency
(54658, 35, 73644, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Necklace of Prowess
(54658, 36, 73492, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Choker of Prowess
(54658, 37, 73493, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Choker of Proficiency
(54658, 38, 73625, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Pendant of Meditation
(54658, 39, 73627, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Pendant of Alacrity
(54658, 40, 73626, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Pendant of Diffusion
(54658, 41, 73640, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Ring of Accuracy
(54658, 42, 73641, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Ring of Cruelty
(54658, 43, 73488, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Signet of Accuracy
(54658, 44, 73489, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Signet of Cruelty
(54658, 45, 73621, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Band of Meditation
(54658, 46, 73622, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Band of Accuracy
(54658, 47, 73623, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Band of Cruelty
(54658, 48, 73591, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Emblem of Meditation
(54658, 50, 73534, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Medallion of Meditation
(54658, 51, 73593, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Emblem of Cruelty
(54658, 53, 73538, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Medallion of Cruelty
(54658, 54, 73592, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Emblem of Tenacity
(54658, 56, 73537, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Medallion of Tenacity
(54658, 57, 73648, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Badge of Conquest
(54658, 58, 73643, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Insignia of Conquest
(54658, 59, 73498, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Badge of Dominance
(54658, 60, 73497, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Insignia of Dominance
(54658, 61, 73496, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Badge of Victory
(54658, 62, 73491, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Insignia of Victory
(54658, 63, 73647, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Cape of Cruelty
(54658, 64, 73646, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Cape of Prowess
(54658, 65, 73495, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Cloak of Alacrity
(54658, 66, 73494, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Cloak of Prowess
(54658, 67, 73628, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Drape of Meditation
(54658, 68, 73629, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Drape of Diffusion
(54658, 69, 73630, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Drape of Prowess
(54658, 70, 73543, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Satin Hood
(54658, 71, 73575, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Silk Cowl
(54658, 72, 73548, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Mooncloth Helm
(54658, 73, 73486, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Felweave Cowl
(54658, 74, 73545, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Mooncloth Mantle
(54658, 75, 73540, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Satin Mantle
(54658, 76, 73572, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Silk Amice
(54658, 77, 73483, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Felweave Amice
(54658, 78, 73637, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Cord of Meditation
(54658, 79, 73638, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Cord of Accuracy
(54658, 80, 73639, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Cord of Cruelty
(54658, 81, 73547, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Mooncloth Leggings
(54658, 82, 73574, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Silk Trousers
(54658, 83, 73485, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Felweave Trousers
(54658, 84, 73542, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Satin Leggings
(54658, 85, 73634, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Treads of Meditation
(54658, 86, 73636, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Treads of Cruelty
(54658, 87, 73635, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Treads of Alacrity
(54658, 88, 73631, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Cuffs of Meditation
(54658, 89, 73633, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Cuffs of Accuracy
(54658, 90, 73632, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Cuffs of Prowess
(54658, 91, 73576, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Silk Handguards
(54658, 92, 73487, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Felweave Handguards
(54658, 93, 73544, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Satin Gloves
(54658, 94, 73549, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Mooncloth Gloves
(54658, 95, 73546, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Mooncloth Robe
(54658, 96, 73573, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Silk Robe
(54658, 97, 73541, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Satin Robe
(54658, 98, 73484, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Felweave Raiment
(54658, 99, 73614, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Dragonhide Helm
(54658, 100, 73525, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Leather Helm
(54658, 101, 73598, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Wyrmhide Helm
(54658, 102, 73606, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Kodohide Helm
(54658, 103, 73611, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Dragonhide Spaulders
(54658, 104, 73523, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Leather Spaulders
(54658, 105, 73603, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Kodohide Spaulders
(54658, 106, 73595, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Wyrmhide Spaulders
(54658, 107, 73527, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Leather Tunic
(54658, 108, 73532, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Waistband of Accuracy
(54658, 109, 73533, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Waistband of Cruelty
(54658, 110, 73610, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Belt of Meditation
(54658, 111, 73602, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Belt of Cruelty
(54658, 112, 73613, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Dragonhide Legguards
(54658, 113, 73524, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Leather Legguards
(54658, 114, 73605, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Kodohide Legguards
(54658, 115, 73597, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Wyrmhide Legguards
(54658, 116, 73531, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Boots of Cruelty
(54658, 117, 73530, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Boots of Alacrity
(54658, 118, 73609, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Footguards of Meditation
(54658, 119, 73601, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Footguards of Alacrity
(54658, 120, 73528, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Armwraps of Accuracy
(54658, 121, 73529, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Armwraps of Alacrity
(54658, 122, 73608, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Bindings of Meditation
(54658, 123, 73600, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Bindings of Prowess
(54658, 124, 73526, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Leather Gloves
(54658, 125, 73615, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Dragonhide Gloves
(54658, 126, 73599, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Wyrmhide Gloves
(54658, 127, 73607, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Kodohide Gloves
(54658, 128, 73612, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Dragonhide Robes
(54658, 129, 73604, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Kodohide Robes
(54658, 130, 73596, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Wyrmhide Robes
(54658, 131, 73582, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Chain Helm
(54658, 132, 73510, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Linked Helm
(54658, 133, 73504, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Mail Helm
(54658, 134, 73515, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Ringmail Helm
(54658, 135, 73580, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Chain Spaulders
(54658, 136, 73508, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Linked Spaulders
(54658, 137, 73513, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Ringmail Spaulders
(54658, 138, 73502, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Mail Spaulders
(54658, 139, 73584, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Chain Armor
(54658, 140, 73512, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Linked Armor
(54658, 141, 73517, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Ringmail Armor
(54658, 142, 73506, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Mail Armor
(54658, 143, 73589, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Links of Accuracy
(54658, 144, 73590, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Links of Cruelty
(54658, 145, 73522, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Waistguard of Meditation
(54658, 146, 73507, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Waistguard of Cruelty
(54658, 147, 73581, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Chain Leggings
(54658, 148, 73509, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Linked Leggings
(54658, 149, 73514, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Ringmail Leggings
(54658, 150, 73503, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Mail Leggings
(54658, 151, 73588, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Sabatons of Cruelty
(54658, 152, 73587, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Sabatons of Alacrity
(54658, 153, 73520, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Sabatons of Meditation
(54658, 154, 73521, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Sabatons of Alacrity
(54658, 155, 73585, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Wristguards of Accuracy
(54658, 156, 73586, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Wristguards of Alacrity
(54658, 157, 73518, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Armbands of Meditation
(54658, 158, 73519, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Armbands of Prowess
(54658, 159, 73583, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Chain Gauntlets
(54658, 160, 73511, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Linked Gauntlets
(54658, 161, 73505, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Mail Gauntlets
(54658, 162, 73516, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Ringmail Gauntlets
(54658, 163, 73618, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Dreadplate Helm
(54658, 164, 73569, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Scaled Helm
(54658, 165, 73480, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Plate Helm
(54658, 166, 73558, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Ornamented Headcover
(54658, 167, 73616, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Dreadplate Shoulders
(54658, 168, 73567, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Scaled Shoulders
(54658, 169, 73478, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Plate Shoulders
(54658, 170, 73556, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Ornamented Spaulders
(54658, 171, 73620, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Dreadplate Chestpiece
(54658, 172, 73571, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Scaled Chestpiece
(54658, 173, 73482, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Plate Chestpiece
(54658, 174, 73560, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Ornamented Chestguard
(54658, 175, 73555, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Girdle of Cruelty
(54658, 176, 73554, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Girdle of Prowess
(54658, 177, 73565, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Clasp of Meditation
(54658, 178, 73566, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Clasp of Cruelty
(54658, 179, 73617, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Dreadplate Legguards
(54658, 180, 73568, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Scaled Legguards
(54658, 181, 73479, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Plate Legguards
(54658, 182, 73557, 0, 3170, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Ornamented Legplates
(54658, 183, 73553, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Warboots of Cruelty
(54658, 184, 73552, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Warboots of Alacrity
(54658, 185, 73563, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Greaves of Meditation
(54658, 186, 73564, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Greaves of Alacrity
(54658, 187, 73550, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Armplates of Alacrity
(54658, 188, 73551, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Armplates of Proficiency
(54658, 189, 73561, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Bracers of Meditation
(54658, 190, 73562, 0, 3168, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Bracers of Prowess
(54658, 191, 73619, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Dreadplate Gauntlets
(54658, 192, 73570, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Scaled Gauntlets
(54658, 193, 73481, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Plate Gauntlets
(54658, 194, 73559, 0, 3169, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Ornamented Gloves
(54658, 195, 73642, 0, 3652, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Relic of Triumph
(54658, 196, 73490, 0, 3652, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Relic of Conquest
(54658, 197, 73624, 0, 3652, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Relic of Dominance
(54658, 198, 73594, 0, 3652, 1, 0, 0, 59185), -- Cataclysmic Gladiator's Relic of Salvation
(54658, 199, 77140, 0, 3872, 1, 0, 0, 59185), -- Stormy Deepholm Iolite
(54658, 200, 77130, 0, 3872, 1, 0, 0, 59185), -- Balanced Elven Peridot
(54658, 201, 77131, 0, 3872, 1, 0, 0, 59185), -- Infused Elven Peridot
(54658, 202, 77154, 0, 3872, 1, 0, 0, 59185), -- Radiant Elven Peridot
(54658, 203, 77137, 0, 3872, 1, 0, 0, 59185), -- Shattered Elven Peridot
(54658, 204, 77139, 0, 3872, 1, 0, 0, 59185), -- Steady Elven Peridot
(54658, 205, 77142, 0, 3872, 1, 0, 0, 59185), -- Turbid Elven Peridot
(54658, 206, 77143, 0, 3872, 1, 0, 0, 59185), -- Vivid Elven Peridot
(54658, 207, 77132, 0, 3872, 1, 0, 0, 59185), -- Lucent Lava Coral
(54658, 208, 77136, 0, 3872, 1, 0, 0, 59185), -- Resplendent Lava Coral
(54658, 209, 77138, 0, 3872, 1, 0, 0, 59185), -- Splendid Lava Coral
(54658, 210, 77141, 0, 3872, 1, 0, 0, 59185), -- Tenuous Lava Coral
(54658, 211, 77144, 0, 3872, 1, 0, 0, 59185), -- Willful Lava Coral
(54658, 212, 77133, 0, 3872, 1, 0, 0, 59185), -- Mysterious Shadow Spinel
(54658, 213, 77134, 0, 3872, 1, 0, 0, 59185), -- Mystic Lightstone
(54659, 1, 68769, 0, 2552, 1, 0, 0, 59185), -- Arcanum of Vicious Agility
(54659, 2, 68770, 0, 2552, 1, 0, 0, 59185), -- Arcanum of Vicious Intellect
(54659, 3, 68768, 0, 2552, 1, 0, 0, 59185), -- Arcanum of Vicious Strength
(54659, 4, 68774, 0, 1005, 1, 0, 0, 59185), -- Greater Inscription of Vicious Agility
(54659, 5, 68772, 0, 1005, 1, 0, 0, 59185), -- Greater Inscription of Vicious Intellect
(54659, 6, 68773, 0, 1005, 1, 0, 0, 59185), -- Greater Inscription of Vicious Strength
(54659, 7, 72307, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Necklace of Proficiency
(54659, 8, 72308, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Necklace of Prowess
(54659, 9, 72454, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Choker of Accuracy
(54659, 10, 72453, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Choker of Proficiency
(54659, 11, 72327, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Pendant of Meditation
(54659, 12, 72325, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Pendant of Alacrity
(54659, 13, 72326, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Pendant of Diffusion
(54659, 14, 72312, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Ring of Accuracy
(54659, 15, 72311, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Ring of Cruelty
(54659, 16, 72458, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Signet of Accuracy
(54659, 17, 72457, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Signet of Cruelty
(54659, 18, 72331, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Band of Meditation
(54659, 19, 72330, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Band of Accuracy
(54659, 20, 72329, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Band of Cruelty
(54659, 21, 72361, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Emblem of Meditation
(54659, 23, 72415, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Medallion of Meditation
(54659, 24, 72359, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Emblem of Cruelty
(54659, 26, 72410, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Medallion of Cruelty
(54659, 27, 72360, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Emblem of Tenacity
(54659, 29, 72413, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Medallion of Tenacity
(54659, 30, 72304, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Badge of Conquest
(54659, 31, 72309, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Insignia of Conquest
(54659, 32, 72448, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Badge of Dominance
(54659, 33, 72449, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Insignia of Dominance
(54659, 34, 72450, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Badge of Victory
(54659, 35, 72455, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Insignia of Victory
(54659, 36, 72305, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Cape of Cruelty
(54659, 37, 72306, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Cape of Prowess
(54659, 38, 72451, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Cloak of Alacrity
(54659, 39, 72452, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Cloak of Prowess
(54659, 40, 72324, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Drape of Meditation
(54659, 41, 72323, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Drape of Diffusion
(54659, 42, 72322, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Drape of Prowess
(54659, 43, 72406, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Satin Hood
(54659, 44, 72374, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Silk Cowl
(54659, 45, 72401, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Mooncloth Helm
(54659, 46, 72460, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Felweave Cowl
(54659, 47, 72404, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Mooncloth Mantle
(54659, 48, 72409, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Satin Mantle
(54659, 49, 72377, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Silk Amice
(54659, 50, 72463, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Felweave Amice
(54659, 51, 72315, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Cord of Meditation
(54659, 52, 72314, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Cord of Accuracy
(54659, 53, 72313, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Cord of Cruelty
(54659, 54, 72402, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Mooncloth Leggings
(54659, 55, 72375, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Silk Trousers
(54659, 56, 72461, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Felweave Trousers
(54659, 57, 72407, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Satin Leggings
(54659, 58, 72318, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Treads of Meditation
(54659, 59, 72316, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Treads of Cruelty
(54659, 60, 72317, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Treads of Alacrity
(54659, 61, 72321, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Cuffs of Meditation
(54659, 62, 72319, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Cuffs of Accuracy
(54659, 63, 72320, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Cuffs of Prowess
(54659, 64, 72373, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Silk Handguards
(54659, 65, 72459, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Felweave Handguards
(54659, 66, 72405, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Satin Gloves
(54659, 67, 72400, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Mooncloth Gloves
(54659, 68, 72403, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Mooncloth Robe
(54659, 69, 72376, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Silk Robe
(54659, 70, 72408, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Satin Robe
(54659, 71, 72462, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Felweave Raiment
(54659, 72, 72338, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Dragonhide Helm
(54659, 73, 72424, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Leather Helm
(54659, 74, 72354, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Wyrmhide Helm
(54659, 75, 72346, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Kodohide Helm
(54659, 76, 72341, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Dragonhide Spaulders
(54659, 77, 72426, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Leather Spaulders
(54659, 78, 72349, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Kodohide Spaulders
(54659, 79, 72357, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Wyrmhide Spaulders
(54659, 80, 72422, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Leather Tunic
(54659, 81, 72417, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Waistband of Accuracy
(54659, 82, 72416, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Waistband of Cruelty
(54659, 83, 72342, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Belt of Meditation
(54659, 84, 72350, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Belt of Cruelty
(54659, 85, 72339, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Dragonhide Legguards
(54659, 86, 72425, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Leather Legguards
(54659, 87, 72347, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Kodohide Legguards
(54659, 88, 72355, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Wyrmhide Legguards
(54659, 89, 72418, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Boots of Cruelty
(54659, 90, 72419, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Boots of Alacrity
(54659, 91, 72343, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Footguards of Meditation
(54659, 92, 72351, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Footguards of Alacrity
(54659, 93, 72421, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Armwraps of Accuracy
(54659, 94, 72420, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Armwraps of Alacrity
(54659, 95, 72344, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Bindings of Meditation
(54659, 96, 72352, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Bindings of Prowess
(54659, 97, 72423, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Leather Gloves
(54659, 98, 72337, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Dragonhide Gloves
(54659, 99, 72353, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Wyrmhide Gloves
(54659, 100, 72345, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Kodohide Gloves
(54659, 101, 72340, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Dragonhide Robes
(54659, 102, 72348, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Kodohide Robes
(54659, 103, 72356, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Wyrmhide Robes
(54659, 104, 72370, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Chain Helm
(54659, 105, 72439, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Linked Helm
(54659, 106, 72445, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Mail Helm
(54659, 107, 72434, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Ringmail Helm
(54659, 108, 72372, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Chain Spaulders
(54659, 109, 72441, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Linked Spaulders
(54659, 110, 72436, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Ringmail Spaulders
(54659, 111, 72447, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Mail Spaulders
(54659, 112, 72368, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Chain Armor
(54659, 113, 72437, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Linked Armor
(54659, 114, 72432, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Ringmail Armor
(54659, 115, 72443, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Mail Armor
(54659, 116, 72363, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Links of Accuracy
(54659, 117, 72362, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Links of Cruelty
(54659, 118, 72427, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Waistguard of Meditation
(54659, 119, 72442, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Waistguard of Cruelty
(54659, 120, 72371, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Chain Leggings
(54659, 121, 72440, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Linked Leggings
(54659, 122, 72435, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Ringmail Leggings
(54659, 123, 72446, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Mail Leggings
(54659, 124, 72364, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Sabatons of Cruelty
(54659, 125, 72365, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Sabatons of Alacrity
(54659, 126, 72429, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Sabatons of Meditation
(54659, 127, 72428, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Sabatons of Alacrity
(54659, 128, 72367, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Wristguards of Accuracy
(54659, 129, 72366, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Wristguards of Alacrity
(54659, 130, 72431, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Armbands of Meditation
(54659, 131, 72430, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Armbands of Prowess
(54659, 132, 72369, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Chain Gauntlets
(54659, 133, 72438, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Linked Gauntlets
(54659, 134, 72444, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Mail Gauntlets
(54659, 135, 72433, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Ringmail Gauntlets
(54659, 136, 72334, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Dreadplate Helm
(54659, 137, 72380, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Scaled Helm
(54659, 138, 72466, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Plate Helm
(54659, 139, 72391, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Ornamented Headcover
(54659, 140, 72336, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Dreadplate Shoulders
(54659, 141, 72382, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Scaled Shoulders
(54659, 142, 72468, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Plate Shoulders
(54659, 143, 72393, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Ornamented Spaulders
(54659, 144, 72332, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Dreadplate Chestpiece
(54659, 145, 72378, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Scaled Chestpiece
(54659, 146, 72464, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Plate Chestpiece
(54659, 147, 72389, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Ornamented Chestguard
(54659, 148, 72394, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Girdle of Accuracy
(54659, 149, 72395, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Girdle of Prowess
(54659, 150, 72384, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Clasp of Meditation
(54659, 151, 72383, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Clasp of Cruelty
(54659, 152, 72335, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Dreadplate Legguards
(54659, 153, 72381, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Scaled Legguards
(54659, 154, 72467, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Plate Legguards
(54659, 155, 72392, 0, 3162, 1, 0, 0, 59185), -- Ruthless Gladiator's Ornamented Legplates
(54659, 156, 72396, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Warboots of Cruelty
(54659, 157, 72397, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Warboots of Alacrity
(54659, 158, 72386, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Greaves of Meditation
(54659, 159, 72385, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Greaves of Alacrity
(54659, 160, 72399, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Armplates of Alacrity
(54659, 161, 72398, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Armplates of Proficiency
(54659, 162, 72388, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Bracers of Meditation
(54659, 163, 72387, 0, 3164, 1, 0, 0, 59185), -- Ruthless Gladiator's Bracers of Prowess
(54659, 164, 72333, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Dreadplate Gauntlets
(54659, 165, 72379, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Scaled Gauntlets
(54659, 166, 72465, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Plate Gauntlets
(54659, 167, 72390, 0, 3163, 1, 0, 0, 59185), -- Ruthless Gladiator's Ornamented Gloves
(54659, 168, 72310, 0, 3552, 1, 0, 0, 59185), -- Ruthless Gladiator's Relic of Triumph
(54659, 169, 72456, 0, 3552, 1, 0, 0, 59185), -- Ruthless Gladiator's Relic of Conquest
(54659, 170, 72328, 0, 3552, 1, 0, 0, 59185), -- Ruthless Gladiator's Relic of Dominance
(54659, 171, 72358, 0, 3552, 1, 0, 0, 59185), -- Ruthless Gladiator's Relic of Salvation
(54659, 172, 70228, 0, 3550, 1, 0, 0, 59185), -- Ruthless Gladiator's Staff
(54659, 173, 70231, 0, 3550, 1, 0, 0, 59185), -- Ruthless Gladiator's Greatsword
(54659, 174, 70226, 0, 3550, 1, 0, 0, 59185), -- Ruthless Gladiator's Battle Staff
(54659, 175, 70213, 0, 3550, 1, 0, 0, 59185), -- Ruthless Gladiator's Decapitator
(54659, 176, 70227, 0, 3550, 1, 0, 0, 59185), -- Ruthless Gladiator's Energy Staff
(54659, 177, 70224, 0, 3550, 1, 0, 0, 59185), -- Ruthless Gladiator's Bonegrinder
(54659, 178, 70225, 0, 3550, 1, 0, 0, 59185), -- Ruthless Gladiator's Pike
(54659, 179, 70239, 0, 3551, 1, 0, 0, 59185), -- Ruthless Gladiator's Endgame
(54659, 180, 70240, 0, 3551, 1, 0, 0, 59185), -- Ruthless Gladiator's Reprieve
(54659, 181, 70220, 0, 3549, 1, 0, 0, 59185), -- Ruthless Gladiator's Right Render
(54659, 182, 70217, 0, 3549, 1, 0, 0, 59185), -- Ruthless Gladiator's Ripper
(54659, 183, 70223, 0, 3549, 1, 0, 0, 59185), -- Ruthless Gladiator's Gavel
(54659, 184, 70216, 0, 3549, 1, 0, 0, 59185), -- Ruthless Gladiator's Spellblade
(54659, 185, 70219, 0, 3551, 1, 0, 0, 59185), -- Ruthless Gladiator's Slasher
(54659, 186, 70215, 0, 3551, 1, 0, 0, 59185), -- Ruthless Gladiator's Shiv
(54659, 187, 70218, 0, 3551, 1, 0, 0, 59185), -- Ruthless Gladiator's Fleshslicer
(54659, 188, 70236, 0, 3550, 1, 0, 0, 59185), -- Ruthless Gladiator's Longbow
(54659, 189, 70234, 0, 3552, 1, 0, 0, 59185), -- Ruthless Gladiator's Touch of Defeat
(54659, 190, 70237, 0, 3550, 1, 0, 0, 59185), -- Ruthless Gladiator's Rifle
(54659, 191, 70238, 0, 3550, 1, 0, 0, 59185), -- Ruthless Gladiator's Heavy Crossbow
(54659, 192, 70235, 0, 3552, 1, 0, 0, 59185), -- Ruthless Gladiator's Baton of Light
(54659, 193, 70241, 0, 3551, 1, 0, 0, 59185), -- Ruthless Gladiator's Shield Wall
(54659, 194, 70242, 0, 3551, 1, 0, 0, 59185), -- Ruthless Gladiator's Barrier
(54659, 195, 70243, 0, 3551, 1, 0, 0, 59185), -- Ruthless Gladiator's Redoubt
(54659, 196, 70232, 0, 3552, 1, 0, 0, 59185), -- Ruthless Gladiator's War Edge
(54659, 197, 70233, 0, 3552, 1, 0, 0, 59185), -- Ruthless Gladiator's Hatchet
(54659, 198, 70222, 0, 3549, 1, 0, 0, 59185), -- Ruthless Gladiator's Bonecracker
(54659, 199, 70214, 0, 3549, 1, 0, 0, 59185), -- Ruthless Gladiator's Shanker
(54659, 200, 70229, 0, 3549, 1, 0, 0, 59185), -- Ruthless Gladiator's Slicer
(54659, 201, 70212, 0, 3549, 1, 0, 0, 59185), -- Ruthless Gladiator's Hacker
(54659, 202, 70221, 0, 3549, 1, 0, 0, 59185), -- Ruthless Gladiator's Pummeler
(54659, 203, 70230, 0, 3549, 1, 0, 0, 59185), -- Ruthless Gladiator's Quickblade
(54659, 204, 70211, 0, 3549, 1, 0, 0, 59185); -- Ruthless Gladiator's Cleaver
