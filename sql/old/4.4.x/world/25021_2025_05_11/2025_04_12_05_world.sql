UPDATE `creature` SET `id`= 54660 WHERE `guid`= 3990008;
UPDATE `creature` SET `id`= 54661 WHERE `guid`= 3990007;
UPDATE `creature` SET `id`= 54662 WHERE `guid`= 3990009;

DELETE FROM `npc_vendor` WHERE `entry` IN (54660, 54661, 54662);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(54660, 1, 73701, 0, 3712, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Ornamented Chestguard
(54660, 2, 73742, 0, 3705, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Dreadplate Chestpiece
(54660, 3, 73718, 0, 3731, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Chain Armor
(54660, 4, 73708, 0, 3722, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Scaled Chestpiece
(54660, 5, 73682, 0, 3772, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Leather Tunic
(54660, 6, 73665, 0, 3748, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Mail Armor
(54660, 7, 73670, 0, 3743, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Linked Armor
(54660, 8, 73675, 0, 3738, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Ringmail Armor
(54660, 9, 73655, 0, 3717, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Plate Chestpiece
(54660, 10, 73743, 0, 3779, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Treads of Meditation
(54660, 11, 73744, 0, 3778, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Treads of Alacrity
(54660, 12, 73745, 0, 3777, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Treads of Cruelty
(54660, 13, 73703, 0, 3710, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Greaves of Alacrity
(54660, 14, 73726, 0, 3759, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Footguards of Alacrity
(54660, 15, 73732, 0, 3758, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Footguards of Meditation
(54660, 16, 73719, 0, 3730, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Sabatons of Alacrity
(54660, 17, 73720, 0, 3729, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Sabatons of Cruelty
(54660, 18, 73683, 0, 3771, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Boots of Alacrity
(54660, 19, 73684, 0, 3770, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Boots of Cruelty
(54660, 20, 73702, 0, 3711, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Greaves of Meditation
(54660, 21, 73695, 0, 3727, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Warboots of Alacrity
(54660, 22, 73696, 0, 3728, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Warboots of Cruelty
(54660, 23, 73676, 0, 3737, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Sabatons of Meditation
(54660, 24, 73677, 0, 3736, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Sabatons of Alacrity
(54660, 25, 73700, 0, 3713, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Ornamented Gloves
(54660, 26, 73737, 0, 3753, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Dragonhide Gloves
(54660, 27, 73713, 0, 3780, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Silk Handguards
(54660, 28, 73741, 0, 3706, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Dreadplate Gauntlets
(54660, 29, 73725, 0, 3765, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Wyrmhide Gloves
(54660, 30, 73717, 0, 3732, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Chain Gauntlets
(54660, 31, 73731, 0, 3760, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Kodohide Gloves
(54660, 32, 73707, 0, 3723, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Scaled Gauntlets
(54660, 33, 73681, 0, 3773, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Leather Gloves
(54660, 34, 73660, 0, 3795, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Felweave Handguards
(54660, 35, 73664, 0, 3749, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Mail Gauntlets
(54660, 36, 73689, 0, 3790, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Satin Gloves
(54660, 37, 73669, 0, 3744, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Linked Gauntlets
(54660, 38, 73694, 0, 3785, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Mooncloth Gloves
(54660, 39, 73654, 0, 3718, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Plate Gauntlets
(54660, 40, 73674, 0, 3739, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Ringmail Gauntlets
(54660, 41, 73736, 0, 3754, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Dragonhide Helm
(54660, 42, 73699, 0, 3714, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Ornamented Headcover
(54660, 43, 73712, 0, 3781, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Silk Cowl
(54660, 44, 73724, 0, 3766, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Wyrmhide Helm
(54660, 45, 73740, 0, 3707, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Dreadplate Helm
(54660, 46, 73716, 0, 3733, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Chain Helm
(54660, 47, 73730, 0, 3761, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Kodohide Helm
(54660, 48, 73706, 0, 3724, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Scaled Helm
(54660, 49, 73680, 0, 3774, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Leather Helm
(54660, 50, 73659, 0, 3796, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Felweave Cowl
(54660, 51, 73663, 0, 3750, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Mail Helm
(54660, 52, 73688, 0, 3791, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Satin Hood
(54660, 53, 73668, 0, 3745, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Linked Helm
(54660, 54, 73693, 0, 3786, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Mooncloth Helm
(54660, 55, 73653, 0, 3719, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Plate Helm
(54660, 56, 73673, 0, 3740, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Ringmail Helm
(54660, 57, 73698, 0, 3715, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Ornamented Legplates
(54660, 58, 73735, 0, 3755, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Dragonhide Legguards
(54660, 59, 73711, 0, 3782, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Silk Trousers
(54660, 60, 73723, 0, 3767, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Wyrmhide Legguards
(54660, 61, 73715, 0, 3734, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Chain Leggings
(54660, 62, 73729, 0, 3762, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Kodohide Legguards
(54660, 63, 73739, 0, 3708, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Dreadplate Legguards
(54660, 64, 73705, 0, 3725, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Scaled Legguards
(54660, 65, 73662, 0, 3751, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Mail Leggings
(54660, 66, 73687, 0, 3792, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Satin Leggings
(54660, 67, 73667, 0, 3746, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Linked Leggings
(54660, 68, 73692, 0, 3787, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Mooncloth Leggings
(54660, 69, 73672, 0, 3741, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Ringmail Leggings
(54660, 70, 73652, 0, 3720, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Plate Legguards
(54660, 71, 73658, 0, 3797, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Felweave Trousers
(54660, 72, 73679, 0, 3775, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Leather Legguards
(54660, 73, 73734, 0, 3756, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Dragonhide Robes
(54660, 74, 73710, 0, 3783, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Silk Robe
(54660, 75, 73722, 0, 3768, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Wyrmhide Robes
(54660, 76, 73728, 0, 3763, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Kodohide Robes
(54660, 77, 73686, 0, 3793, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Satin Robe
(54660, 78, 73691, 0, 3788, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Mooncloth Robe
(54660, 79, 73657, 0, 3798, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Felweave Raiment
(54660, 80, 73738, 0, 3709, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Dreadplate Shoulders
(54660, 81, 73714, 0, 3735, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Chain Spaulders
(54660, 82, 73704, 0, 3726, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Scaled Shoulders
(54660, 83, 73733, 0, 3757, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Dragonhide Spaulders
(54660, 84, 73721, 0, 3769, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Wyrmhide Spaulders
(54660, 85, 73727, 0, 3764, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Kodohide Spaulders
(54660, 86, 73697, 0, 3716, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Ornamented Spaulders
(54660, 87, 73709, 0, 3784, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Silk Amice
(54660, 88, 73661, 0, 3752, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Mail Spaulders
(54660, 89, 73685, 0, 3794, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Satin Mantle
(54660, 90, 73690, 0, 3789, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Mooncloth Mantle
(54660, 91, 73666, 0, 3747, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Linked Spaulders
(54660, 92, 73671, 0, 3742, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Ringmail Spaulders
(54660, 93, 73651, 0, 3721, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Plate Shoulders
(54660, 94, 73656, 0, 3799, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Felweave Amice
(54660, 95, 73678, 0, 3776, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Leather Spaulders
(54660, 96, 73433, 0, 3655, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Battle Staff
(54660, 97, 73443, 0, 3656, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Bonegrinder
(54660, 98, 73423, 0, 3657, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Pike
(54660, 99, 73424, 0, 3658, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Energy Staff
(54660, 100, 73429, 0, 3659, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Staff
(54660, 101, 73444, 0, 3660, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Decapitator
(54660, 102, 73442, 0, 3661, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Greatsword
(54660, 103, 73436, 0, 3663, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Endgame
(54660, 104, 73432, 0, 3662, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Reprieve
(54660, 105, 73419, 0, 3664, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Right Render
(54660, 106, 73421, 0, 3665, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Ripper
(54660, 107, 73426, 0, 3666, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Gavel
(54660, 108, 73434, 0, 3667, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Spellblade
(54660, 109, 73428, 0, 3668, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Shiv
(54660, 110, 73418, 0, 3669, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Slasher
(54660, 111, 73420, 0, 3670, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Fleshslicer
(54660, 112, 73437, 0, 3671, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Longbow
(54660, 113, 73417, 0, 3672, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Baton of Light
(54660, 114, 73427, 0, 3673, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Rifle
(54660, 115, 73430, 0, 3674, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Heavy Crossbow
(54660, 116, 73431, 0, 3675, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Touch of Defeat
(54660, 117, 73413, 0, 3676, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Shield Wall
(54660, 118, 73435, 0, 3677, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Barrier
(54660, 119, 73425, 0, 3678, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Redoubt
(54660, 120, 73438, 0, 3679, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Hatchet
(54660, 121, 73412, 0, 3680, 1, 0, 0, 60192), -- Cataclysmic Gladiator's War Edge
(54660, 122, 73439, 0, 3681, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Quickblade
(54660, 123, 73440, 0, 3682, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Pummeler
(54660, 124, 73414, 0, 3683, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Slicer
(54660, 125, 73415, 0, 3684, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Bonecracker
(54660, 126, 73416, 0, 3685, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Hacker
(54660, 127, 73441, 0, 3686, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Cleaver
(54660, 128, 73422, 0, 3687, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Shanker
(54660, 129, 74783, 0, 3695, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Relic of Conquest
(54660, 130, 74784, 0, 3696, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Relic of Salvation
(54660, 131, 74785, 0, 3697, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Relic of Dominance
(54660, 132, 74786, 0, 3698, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Relic of Triumph
-- 
(54661, 1, 73462, 0, 3415, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Staff
(54661, 2, 73456, 0, 3415, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Pike
(54661, 3, 73457, 0, 3415, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Energy Staff
(54661, 4, 73475, 0, 3415, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Greatsword
(54661, 5, 73466, 0, 3415, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Battle Staff
(54661, 6, 73476, 0, 3415, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Bonegrinder
(54661, 7, 73477, 0, 3415, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Decapitator
(54661, 8, 73465, 0, 3417, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Reprieve
(54661, 9, 73469, 0, 3417, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Endgame
(54661, 10, 73467, 0, 3416, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Spellblade
(54661, 11, 73452, 0, 3416, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Right Render
(54661, 12, 73454, 0, 3416, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Ripper
(54661, 13, 73459, 0, 3416, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Gavel
(54661, 14, 73461, 0, 3417, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Shiv
(54661, 15, 73451, 0, 3417, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Slasher
(54661, 16, 73453, 0, 3417, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Fleshslicer
(54661, 17, 73470, 0, 3415, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Longbow
(54661, 18, 73464, 0, 3652, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Touch of Defeat
(54661, 19, 73460, 0, 3415, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Rifle
(54661, 20, 73463, 0, 3415, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Heavy Crossbow
(54661, 21, 73450, 0, 3652, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Baton of Light
(54661, 22, 73446, 0, 3417, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Shield Wall
(54661, 23, 73458, 0, 3417, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Redoubt
(54661, 24, 73468, 0, 3417, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Barrier
(54661, 25, 73445, 0, 3652, 1, 0, 0, 60192), -- Cataclysmic Gladiator's War Edge
(54661, 26, 73471, 0, 3652, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Hatchet
(54661, 27, 73455, 0, 3416, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Shanker
(54661, 28, 73447, 0, 3416, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Slicer
(54661, 29, 73473, 0, 3416, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Pummeler
(54661, 30, 73472, 0, 3416, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Quickblade
(54661, 31, 73449, 0, 3416, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Hacker
(54661, 32, 73448, 0, 3416, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Bonecracker
(54661, 33, 73474, 0, 3416, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Cleaver
(54661, 34, 73645, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Necklace of Proficiency
(54661, 35, 73644, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Necklace of Prowess
(54661, 36, 73492, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Choker of Prowess
(54661, 37, 73493, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Choker of Proficiency
(54661, 38, 73625, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Pendant of Meditation
(54661, 39, 73627, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Pendant of Alacrity
(54661, 40, 73626, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Pendant of Diffusion
(54661, 41, 73640, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Ring of Accuracy
(54661, 42, 73641, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Ring of Cruelty
(54661, 43, 73488, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Signet of Accuracy
(54661, 44, 73489, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Signet of Cruelty
(54661, 45, 73621, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Band of Meditation
(54661, 46, 73622, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Band of Accuracy
(54661, 47, 73623, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Band of Cruelty
(54661, 48, 73591, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Emblem of Meditation
(54661, 49, 73535, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Medallion of Meditation
(54661, 51, 73593, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Emblem of Cruelty
(54661, 52, 73539, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Medallion of Cruelty
(54661, 54, 73592, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Emblem of Tenacity
(54661, 55, 73536, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Medallion of Tenacity
(54661, 57, 73648, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Badge of Conquest
(54661, 58, 73643, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Insignia of Conquest
(54661, 59, 73498, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Badge of Dominance
(54661, 60, 73497, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Insignia of Dominance
(54661, 61, 73496, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Badge of Victory
(54661, 62, 73491, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Insignia of Victory
(54661, 63, 73647, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Cape of Cruelty
(54661, 64, 73646, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Cape of Prowess
(54661, 65, 73495, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Cloak of Alacrity
(54661, 66, 73494, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Cloak of Prowess
(54661, 67, 73628, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Drape of Meditation
(54661, 68, 73629, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Drape of Diffusion
(54661, 69, 73630, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Drape of Prowess
(54661, 70, 73543, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Satin Hood
(54661, 71, 73575, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Silk Cowl
(54661, 72, 73548, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Mooncloth Helm
(54661, 73, 73486, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Felweave Cowl
(54661, 74, 73545, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Mooncloth Mantle
(54661, 75, 73540, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Satin Mantle
(54661, 76, 73572, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Silk Amice
(54661, 77, 73483, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Felweave Amice
(54661, 78, 73637, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Cord of Meditation
(54661, 79, 73638, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Cord of Accuracy
(54661, 80, 73639, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Cord of Cruelty
(54661, 81, 73547, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Mooncloth Leggings
(54661, 82, 73574, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Silk Trousers
(54661, 83, 73485, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Felweave Trousers
(54661, 84, 73542, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Satin Leggings
(54661, 85, 73634, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Treads of Meditation
(54661, 86, 73636, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Treads of Cruelty
(54661, 87, 73635, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Treads of Alacrity
(54661, 88, 73631, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Cuffs of Meditation
(54661, 89, 73633, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Cuffs of Accuracy
(54661, 90, 73632, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Cuffs of Prowess
(54661, 91, 73576, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Silk Handguards
(54661, 92, 73487, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Felweave Handguards
(54661, 93, 73544, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Satin Gloves
(54661, 94, 73549, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Mooncloth Gloves
(54661, 95, 73546, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Mooncloth Robe
(54661, 96, 73573, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Silk Robe
(54661, 97, 73541, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Satin Robe
(54661, 98, 73484, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Felweave Raiment
(54661, 99, 73614, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Dragonhide Helm
(54661, 100, 73525, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Leather Helm
(54661, 101, 73598, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Wyrmhide Helm
(54661, 102, 73606, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Kodohide Helm
(54661, 103, 73611, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Dragonhide Spaulders
(54661, 104, 73523, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Leather Spaulders
(54661, 105, 73603, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Kodohide Spaulders
(54661, 106, 73595, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Wyrmhide Spaulders
(54661, 107, 73527, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Leather Tunic
(54661, 108, 73532, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Waistband of Accuracy
(54661, 109, 73533, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Waistband of Cruelty
(54661, 110, 73610, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Belt of Meditation
(54661, 111, 73602, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Belt of Cruelty
(54661, 112, 73613, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Dragonhide Legguards
(54661, 113, 73524, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Leather Legguards
(54661, 114, 73605, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Kodohide Legguards
(54661, 115, 73597, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Wyrmhide Legguards
(54661, 116, 73531, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Boots of Cruelty
(54661, 117, 73530, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Boots of Alacrity
(54661, 118, 73609, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Footguards of Meditation
(54661, 119, 73601, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Footguards of Alacrity
(54661, 120, 73528, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Armwraps of Accuracy
(54661, 121, 73529, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Armwraps of Alacrity
(54661, 122, 73608, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Bindings of Meditation
(54661, 123, 73600, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Bindings of Prowess
(54661, 124, 73526, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Leather Gloves
(54661, 125, 73615, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Dragonhide Gloves
(54661, 126, 73599, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Wyrmhide Gloves
(54661, 127, 73607, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Kodohide Gloves
(54661, 128, 73612, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Dragonhide Robes
(54661, 129, 73604, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Kodohide Robes
(54661, 130, 73596, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Wyrmhide Robes
(54661, 131, 73582, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Chain Helm
(54661, 132, 73510, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Linked Helm
(54661, 133, 73504, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Mail Helm
(54661, 134, 73515, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Ringmail Helm
(54661, 135, 73580, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Chain Spaulders
(54661, 136, 73508, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Linked Spaulders
(54661, 137, 73513, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Ringmail Spaulders
(54661, 138, 73502, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Mail Spaulders
(54661, 139, 73584, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Chain Armor
(54661, 140, 73512, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Linked Armor
(54661, 141, 73517, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Ringmail Armor
(54661, 142, 73506, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Mail Armor
(54661, 143, 73589, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Links of Accuracy
(54661, 144, 73590, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Links of Cruelty
(54661, 145, 73522, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Waistguard of Meditation
(54661, 146, 73507, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Waistguard of Cruelty
(54661, 147, 73581, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Chain Leggings
(54661, 148, 73509, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Linked Leggings
(54661, 149, 73514, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Ringmail Leggings
(54661, 150, 73503, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Mail Leggings
(54661, 151, 73588, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Sabatons of Cruelty
(54661, 152, 73587, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Sabatons of Alacrity
(54661, 153, 73520, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Sabatons of Meditation
(54661, 154, 73521, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Sabatons of Alacrity
(54661, 155, 73585, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Wristguards of Accuracy
(54661, 156, 73586, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Wristguards of Alacrity
(54661, 157, 73518, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Armbands of Meditation
(54661, 158, 73519, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Armbands of Prowess
(54661, 159, 73583, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Chain Gauntlets
(54661, 160, 73511, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Linked Gauntlets
(54661, 161, 73505, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Mail Gauntlets
(54661, 162, 73516, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Ringmail Gauntlets
(54661, 163, 73618, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Dreadplate Helm
(54661, 164, 73569, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Scaled Helm
(54661, 165, 73480, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Plate Helm
(54661, 166, 73558, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Ornamented Headcover
(54661, 167, 73616, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Dreadplate Shoulders
(54661, 168, 73567, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Scaled Shoulders
(54661, 169, 73478, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Plate Shoulders
(54661, 170, 73556, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Ornamented Spaulders
(54661, 171, 73620, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Dreadplate Chestpiece
(54661, 172, 73571, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Scaled Chestpiece
(54661, 173, 73482, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Plate Chestpiece
(54661, 174, 73560, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Ornamented Chestguard
(54661, 175, 73555, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Girdle of Cruelty
(54661, 176, 73554, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Girdle of Prowess
(54661, 177, 73565, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Clasp of Meditation
(54661, 178, 73566, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Clasp of Cruelty
(54661, 179, 73617, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Dreadplate Legguards
(54661, 180, 73568, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Scaled Legguards
(54661, 181, 73479, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Plate Legguards
(54661, 182, 73557, 0, 3170, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Ornamented Legplates
(54661, 183, 73553, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Warboots of Cruelty
(54661, 184, 73552, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Warboots of Alacrity
(54661, 185, 73563, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Greaves of Meditation
(54661, 186, 73564, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Greaves of Alacrity
(54661, 187, 73550, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Armplates of Alacrity
(54661, 188, 73551, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Armplates of Proficiency
(54661, 189, 73561, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Bracers of Meditation
(54661, 190, 73562, 0, 3168, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Bracers of Prowess
(54661, 191, 73619, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Dreadplate Gauntlets
(54661, 192, 73570, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Scaled Gauntlets
(54661, 193, 73481, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Plate Gauntlets
(54661, 194, 73559, 0, 3169, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Ornamented Gloves
(54661, 195, 73642, 0, 3652, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Relic of Triumph
(54661, 196, 73490, 0, 3652, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Relic of Conquest
(54661, 197, 73624, 0, 3652, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Relic of Dominance
(54661, 198, 73594, 0, 3652, 1, 0, 0, 60192), -- Cataclysmic Gladiator's Relic of Salvation
(54661, 199, 77140, 0, 3872, 1, 0, 0, 60192), -- Stormy Deepholm Iolite
(54661, 200, 77130, 0, 3872, 1, 0, 0, 60192), -- Balanced Elven Peridot
(54661, 201, 77131, 0, 3872, 1, 0, 0, 60192), -- Infused Elven Peridot
(54661, 202, 77154, 0, 3872, 1, 0, 0, 60192), -- Radiant Elven Peridot
(54661, 203, 77137, 0, 3872, 1, 0, 0, 60192), -- Shattered Elven Peridot
(54661, 204, 77139, 0, 3872, 1, 0, 0, 60192), -- Steady Elven Peridot
(54661, 205, 77142, 0, 3872, 1, 0, 0, 60192), -- Turbid Elven Peridot
(54661, 206, 77143, 0, 3872, 1, 0, 0, 60192), -- Vivid Elven Peridot
(54661, 207, 77132, 0, 3872, 1, 0, 0, 60192), -- Lucent Lava Coral
(54661, 208, 77136, 0, 3872, 1, 0, 0, 60192), -- Resplendent Lava Coral
(54661, 209, 77138, 0, 3872, 1, 0, 0, 60192), -- Splendid Lava Coral
(54661, 210, 77141, 0, 3872, 1, 0, 0, 60192), -- Tenuous Lava Coral
(54661, 211, 77144, 0, 3872, 1, 0, 0, 60192), -- Willful Lava Coral
(54661, 212, 77133, 0, 3872, 1, 0, 0, 60192), -- Mysterious Shadow Spinel
(54661, 213, 77134, 0, 3872, 1, 0, 0, 60192), -- Mystic Lightstone
-- 
(54662, 1, 68769, 0, 2552, 1, 0, 0, 60192), -- Arcanum of Vicious Agility
(54662, 2, 68770, 0, 2552, 1, 0, 0, 60192), -- Arcanum of Vicious Intellect
(54662, 3, 68768, 0, 2552, 1, 0, 0, 60192), -- Arcanum of Vicious Strength
(54662, 4, 68774, 0, 1005, 1, 0, 0, 60192), -- Greater Inscription of Vicious Agility
(54662, 5, 68772, 0, 1005, 1, 0, 0, 60192), -- Greater Inscription of Vicious Intellect
(54662, 6, 68773, 0, 1005, 1, 0, 0, 60192), -- Greater Inscription of Vicious Strength
(54662, 7, 72307, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Necklace of Proficiency
(54662, 8, 72308, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Necklace of Prowess
(54662, 9, 72454, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Choker of Accuracy
(54662, 10, 72453, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Choker of Proficiency
(54662, 11, 72327, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Pendant of Meditation
(54662, 12, 72325, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Pendant of Alacrity
(54662, 13, 72326, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Pendant of Diffusion
(54662, 14, 72312, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Ring of Accuracy
(54662, 15, 72311, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Ring of Cruelty
(54662, 16, 72458, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Signet of Accuracy
(54662, 17, 72457, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Signet of Cruelty
(54662, 18, 72331, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Band of Meditation
(54662, 19, 72330, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Band of Accuracy
(54662, 20, 72329, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Band of Cruelty
(54662, 21, 72361, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Emblem of Meditation
(54662, 22, 72414, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Medallion of Meditation
(54662, 24, 72359, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Emblem of Cruelty
(54662, 25, 72411, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Medallion of Cruelty
(54662, 27, 72360, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Emblem of Tenacity
(54662, 28, 72412, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Medallion of Tenacity
(54662, 30, 72304, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Badge of Conquest
(54662, 31, 72309, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Insignia of Conquest
(54662, 32, 72448, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Badge of Dominance
(54662, 33, 72449, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Insignia of Dominance
(54662, 34, 72450, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Badge of Victory
(54662, 35, 72455, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Insignia of Victory
(54662, 36, 72305, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Cape of Cruelty
(54662, 37, 72306, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Cape of Prowess
(54662, 38, 72451, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Cloak of Alacrity
(54662, 39, 72452, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Cloak of Prowess
(54662, 40, 72324, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Drape of Meditation
(54662, 41, 72323, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Drape of Diffusion
(54662, 42, 72322, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Drape of Prowess
(54662, 43, 72406, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Satin Hood
(54662, 44, 72374, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Silk Cowl
(54662, 45, 72401, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Mooncloth Helm
(54662, 46, 72460, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Felweave Cowl
(54662, 47, 72404, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Mooncloth Mantle
(54662, 48, 72409, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Satin Mantle
(54662, 49, 72377, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Silk Amice
(54662, 50, 72463, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Felweave Amice
(54662, 51, 72315, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Cord of Meditation
(54662, 52, 72314, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Cord of Accuracy
(54662, 53, 72313, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Cord of Cruelty
(54662, 54, 72402, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Mooncloth Leggings
(54662, 55, 72375, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Silk Trousers
(54662, 56, 72461, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Felweave Trousers
(54662, 57, 72407, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Satin Leggings
(54662, 58, 72318, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Treads of Meditation
(54662, 59, 72316, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Treads of Cruelty
(54662, 60, 72317, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Treads of Alacrity
(54662, 61, 72321, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Cuffs of Meditation
(54662, 62, 72319, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Cuffs of Accuracy
(54662, 63, 72320, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Cuffs of Prowess
(54662, 64, 72373, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Silk Handguards
(54662, 65, 72459, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Felweave Handguards
(54662, 66, 72405, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Satin Gloves
(54662, 67, 72400, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Mooncloth Gloves
(54662, 68, 72403, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Mooncloth Robe
(54662, 69, 72376, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Silk Robe
(54662, 70, 72408, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Satin Robe
(54662, 71, 72462, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Felweave Raiment
(54662, 72, 72338, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Dragonhide Helm
(54662, 73, 72424, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Leather Helm
(54662, 74, 72354, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Wyrmhide Helm
(54662, 75, 72346, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Kodohide Helm
(54662, 76, 72341, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Dragonhide Spaulders
(54662, 77, 72426, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Leather Spaulders
(54662, 78, 72349, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Kodohide Spaulders
(54662, 79, 72357, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Wyrmhide Spaulders
(54662, 80, 72422, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Leather Tunic
(54662, 81, 72417, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Waistband of Accuracy
(54662, 82, 72416, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Waistband of Cruelty
(54662, 83, 72342, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Belt of Meditation
(54662, 84, 72350, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Belt of Cruelty
(54662, 85, 72339, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Dragonhide Legguards
(54662, 86, 72425, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Leather Legguards
(54662, 87, 72347, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Kodohide Legguards
(54662, 88, 72355, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Wyrmhide Legguards
(54662, 89, 72418, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Boots of Cruelty
(54662, 90, 72419, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Boots of Alacrity
(54662, 91, 72343, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Footguards of Meditation
(54662, 92, 72351, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Footguards of Alacrity
(54662, 93, 72421, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Armwraps of Accuracy
(54662, 94, 72420, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Armwraps of Alacrity
(54662, 95, 72344, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Bindings of Meditation
(54662, 96, 72352, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Bindings of Prowess
(54662, 97, 72423, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Leather Gloves
(54662, 98, 72337, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Dragonhide Gloves
(54662, 99, 72353, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Wyrmhide Gloves
(54662, 100, 72345, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Kodohide Gloves
(54662, 101, 72340, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Dragonhide Robes
(54662, 102, 72348, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Kodohide Robes
(54662, 103, 72356, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Wyrmhide Robes
(54662, 104, 72370, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Chain Helm
(54662, 105, 72439, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Linked Helm
(54662, 106, 72445, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Mail Helm
(54662, 107, 72434, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Ringmail Helm
(54662, 108, 72372, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Chain Spaulders
(54662, 109, 72441, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Linked Spaulders
(54662, 110, 72436, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Ringmail Spaulders
(54662, 111, 72447, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Mail Spaulders
(54662, 112, 72368, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Chain Armor
(54662, 113, 72437, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Linked Armor
(54662, 114, 72432, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Ringmail Armor
(54662, 115, 72443, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Mail Armor
(54662, 116, 72363, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Links of Accuracy
(54662, 117, 72362, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Links of Cruelty
(54662, 118, 72427, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Waistguard of Meditation
(54662, 119, 72442, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Waistguard of Cruelty
(54662, 120, 72371, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Chain Leggings
(54662, 121, 72440, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Linked Leggings
(54662, 122, 72435, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Ringmail Leggings
(54662, 123, 72446, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Mail Leggings
(54662, 124, 72364, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Sabatons of Cruelty
(54662, 125, 72365, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Sabatons of Alacrity
(54662, 126, 72429, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Sabatons of Meditation
(54662, 127, 72428, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Sabatons of Alacrity
(54662, 128, 72367, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Wristguards of Accuracy
(54662, 129, 72366, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Wristguards of Alacrity
(54662, 130, 72431, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Armbands of Meditation
(54662, 131, 72430, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Armbands of Prowess
(54662, 132, 72369, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Chain Gauntlets
(54662, 133, 72438, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Linked Gauntlets
(54662, 134, 72444, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Mail Gauntlets
(54662, 135, 72433, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Ringmail Gauntlets
(54662, 136, 72334, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Dreadplate Helm
(54662, 137, 72380, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Scaled Helm
(54662, 138, 72466, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Plate Helm
(54662, 139, 72391, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Ornamented Headcover
(54662, 140, 72336, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Dreadplate Shoulders
(54662, 141, 72382, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Scaled Shoulders
(54662, 142, 72468, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Plate Shoulders
(54662, 143, 72393, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Ornamented Spaulders
(54662, 144, 72332, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Dreadplate Chestpiece
(54662, 145, 72378, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Scaled Chestpiece
(54662, 146, 72464, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Plate Chestpiece
(54662, 147, 72389, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Ornamented Chestguard
(54662, 148, 72394, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Girdle of Accuracy
(54662, 149, 72395, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Girdle of Prowess
(54662, 150, 72384, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Clasp of Meditation
(54662, 151, 72383, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Clasp of Cruelty
(54662, 152, 72335, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Dreadplate Legguards
(54662, 153, 72381, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Scaled Legguards
(54662, 154, 72467, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Plate Legguards
(54662, 155, 72392, 0, 3162, 1, 0, 0, 60192), -- Ruthless Gladiator's Ornamented Legplates
(54662, 156, 72396, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Warboots of Cruelty
(54662, 157, 72397, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Warboots of Alacrity
(54662, 158, 72386, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Greaves of Meditation
(54662, 159, 72385, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Greaves of Alacrity
(54662, 160, 72399, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Armplates of Alacrity
(54662, 161, 72398, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Armplates of Proficiency
(54662, 162, 72388, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Bracers of Meditation
(54662, 163, 72387, 0, 3164, 1, 0, 0, 60192), -- Ruthless Gladiator's Bracers of Prowess
(54662, 164, 72333, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Dreadplate Gauntlets
(54662, 165, 72379, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Scaled Gauntlets
(54662, 166, 72465, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Plate Gauntlets
(54662, 167, 72390, 0, 3163, 1, 0, 0, 60192), -- Ruthless Gladiator's Ornamented Gloves
(54662, 168, 72310, 0, 3552, 1, 0, 0, 60192), -- Ruthless Gladiator's Relic of Triumph
(54662, 169, 72456, 0, 3552, 1, 0, 0, 60192), -- Ruthless Gladiator's Relic of Conquest
(54662, 170, 72328, 0, 3552, 1, 0, 0, 60192), -- Ruthless Gladiator's Relic of Dominance
(54662, 171, 72358, 0, 3552, 1, 0, 0, 60192), -- Ruthless Gladiator's Relic of Salvation
(54662, 172, 70228, 0, 3550, 1, 0, 0, 60192), -- Ruthless Gladiator's Staff
(54662, 173, 70231, 0, 3550, 1, 0, 0, 60192), -- Ruthless Gladiator's Greatsword
(54662, 174, 70226, 0, 3550, 1, 0, 0, 60192), -- Ruthless Gladiator's Battle Staff
(54662, 175, 70213, 0, 3550, 1, 0, 0, 60192), -- Ruthless Gladiator's Decapitator
(54662, 176, 70227, 0, 3550, 1, 0, 0, 60192), -- Ruthless Gladiator's Energy Staff
(54662, 177, 70224, 0, 3550, 1, 0, 0, 60192), -- Ruthless Gladiator's Bonegrinder
(54662, 178, 70225, 0, 3550, 1, 0, 0, 60192), -- Ruthless Gladiator's Pike
(54662, 179, 70239, 0, 3551, 1, 0, 0, 60192), -- Ruthless Gladiator's Endgame
(54662, 180, 70240, 0, 3551, 1, 0, 0, 60192), -- Ruthless Gladiator's Reprieve
(54662, 181, 70220, 0, 3549, 1, 0, 0, 60192), -- Ruthless Gladiator's Right Render
(54662, 182, 70217, 0, 3549, 1, 0, 0, 60192), -- Ruthless Gladiator's Ripper
(54662, 183, 70223, 0, 3549, 1, 0, 0, 60192), -- Ruthless Gladiator's Gavel
(54662, 184, 70216, 0, 3549, 1, 0, 0, 60192), -- Ruthless Gladiator's Spellblade
(54662, 185, 70219, 0, 3551, 1, 0, 0, 60192), -- Ruthless Gladiator's Slasher
(54662, 186, 70215, 0, 3551, 1, 0, 0, 60192), -- Ruthless Gladiator's Shiv
(54662, 187, 70218, 0, 3551, 1, 0, 0, 60192), -- Ruthless Gladiator's Fleshslicer
(54662, 188, 70236, 0, 3550, 1, 0, 0, 60192), -- Ruthless Gladiator's Longbow
(54662, 189, 70234, 0, 3552, 1, 0, 0, 60192), -- Ruthless Gladiator's Touch of Defeat
(54662, 190, 70237, 0, 3550, 1, 0, 0, 60192), -- Ruthless Gladiator's Rifle
(54662, 191, 70238, 0, 3550, 1, 0, 0, 60192), -- Ruthless Gladiator's Heavy Crossbow
(54662, 192, 70235, 0, 3552, 1, 0, 0, 60192), -- Ruthless Gladiator's Baton of Light
(54662, 193, 70241, 0, 3551, 1, 0, 0, 60192), -- Ruthless Gladiator's Shield Wall
(54662, 194, 70242, 0, 3551, 1, 0, 0, 60192), -- Ruthless Gladiator's Barrier
(54662, 195, 70243, 0, 3551, 1, 0, 0, 60192), -- Ruthless Gladiator's Redoubt
(54662, 196, 70232, 0, 3552, 1, 0, 0, 60192), -- Ruthless Gladiator's War Edge
(54662, 197, 70233, 0, 3552, 1, 0, 0, 60192), -- Ruthless Gladiator's Hatchet
(54662, 198, 70222, 0, 3549, 1, 0, 0, 60192), -- Ruthless Gladiator's Bonecracker
(54662, 199, 70214, 0, 3549, 1, 0, 0, 60192), -- Ruthless Gladiator's Shanker
(54662, 200, 70229, 0, 3549, 1, 0, 0, 60192), -- Ruthless Gladiator's Slicer
(54662, 201, 70212, 0, 3549, 1, 0, 0, 60192), -- Ruthless Gladiator's Hacker
(54662, 202, 70221, 0, 3549, 1, 0, 0, 60192), -- Ruthless Gladiator's Pummeler
(54662, 203, 70230, 0, 3549, 1, 0, 0, 60192), -- Ruthless Gladiator's Quickblade
(54662, 204, 70211, 0, 3549, 1, 0, 0, 60192); -- Ruthless Gladiator's Cleaver
