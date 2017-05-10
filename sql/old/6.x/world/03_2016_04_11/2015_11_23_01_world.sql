-- Twilight Highlands Area: 5140 Highbank Phase 169
SET @CGUID := 250151;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+247;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 45167, 0, 1, 169, 0, -4907.8, -6605.99, 20.28953, 5.445427, 120, 0, 0), -- Kurdran Wildhammer
(@CGUID+1, 45170, 0, 1, 169, 0, -4916.22, -6616.91, 19.04593, 0.01745329, 120, 0, 0), -- Simon Chandler
(@CGUID+2, 45173, 0, 1, 169, 0, -4885.1, -6623.98, 9.904303, 4.869469, 120, 0, 0), -- Talaa
(@CGUID+3, 50381, 0, 1, 169, 0, -4838.097, -6589.958, 9.648396, 0.122173, 120, 0, 0), -- Misty Merriweather <Hide & Leather Trader>
(@CGUID+4, 50382, 0, 1, 169, 0, -4847.408, -6610.934, 9.500094, 0.8377581, 120, 0, 0), -- Brundall Chiselgut <Metal Trader>
(@CGUID+5, 50386, 0, 1, 169, 0, -4860.052, -6576.734, 9.500094, 5.427974, 120, 0, 0), -- Sal Ferraga <Cloth Trader>
(@CGUID+6, 50458, 0, 1, 169, 0, -4864.509, -6586.958, 9.500094, 0, 120, 0, 0), -- Deorim <Enchanting Supplies>
(@CGUID+7, 45256, 0, 1, 169, 0, -4968.62, -6452, 5.86154, 0.7679449, 120, 0, 0), -- Dave's Camera Bunny
(@CGUID+8, 45869, 0, 1, 169, 0, -4899.32, -6645.05, 33.39563, 1.169371, 120, 0, 0), -- Highbank Shaman
(@CGUID+9, 45869, 0, 1, 169, 0, -4880.32, -6646.61, 33.39573, 2.024582, 120, 0, 0), -- Highbank Shaman
(@CGUID+10, 45869, 0, 1, 169, 0, -4872.19, -6639.9, 33.39553, 2.478368, 120, 0, 0), -- Highbank Shaman
(@CGUID+11, 45869, 0, 1, 169, 0, -4867.2, -6624.95, 33.39553, 3.141593, 120, 0, 0), -- Highbank Shaman
(@CGUID+12, 45869, 0, 1, 169, 0, -4901.56, -6637.1, 10.92023, 0.8377581, 120, 0, 0), -- Highbank Shaman
(@CGUID+13, 45869, 0, 1, 169, 0, -4877.61, -6615.96, 10.92323, 3.612832, 120, 0, 0), -- Highbank Shaman
(@CGUID+14, 47119, 0, 1, 169, 0, -4866.6, -6741.57, 9.500103, 0, 120, 0, 0), -- Glenn Arbuckle <Gryphon Master>
(@CGUID+15, 49008, 0, 1, 169, 0, -4861.115, -6678.806, 8.240196, 1.553343, 120, 0, 0), -- Axebite Infantry
(@CGUID+16, 49008, 0, 1, 169, 0, -4847.016, -6674.309, 6.887068, 2.408554, 120, 0, 0), -- Axebite Infantry
(@CGUID+17, 49008, 0, 1, 169, 0, -4903.969, -6730.637, 0.7164544, 0.8377581, 120, 0, 0), -- Axebite Infantry
(@CGUID+18, 49008, 0, 1, 169, 0, -4860.255, -6671.849, 8.488512, 1.745329, 120, 0, 0), -- Axebite Infantry
(@CGUID+19, 49008, 0, 1, 169, 0, -4855.073, -6673.564, 7.895617, 1.867502, 120, 0, 0), -- Axebite Infantry
(@CGUID+20, 49008, 0, 1, 169, 0, -4925.936, -6743.022, 5.578823, 0.8203048, 120, 0, 0), -- Axebite Infantry
(@CGUID+21, 49008, 0, 1, 169, 0, -4869.255, -6716.262, 5.013374, 1.012291, 120, 0, 0), -- Axebite Infantry
(@CGUID+22, 49008, 0, 1, 169, 0, -4825.771, -6690.893, 4.413385, 5.951573, 120, 0, 0), -- Axebite Infantry
(@CGUID+23, 49008, 0, 1, 169, 0, -4858.743, -6669.259, 8.462119, 1.745329, 120, 0, 0), -- Axebite Infantry
(@CGUID+24, 49008, 0, 1, 169, 0, -4890.707, -6716.463, 4.898449, 0.4886922, 120, 0, 0), -- Axebite Infantry
(@CGUID+25, 49008, 0, 1, 169, 0, -4908.384, -6728.556, 0.7164544, 0.4014257, 120, 0, 0), -- Axebite Infantry
(@CGUID+26, 49008, 0, 1, 169, 0, -4927.963, -6740.297, 5.508946, 0.2443461, 120, 0, 0), -- Axebite Infantry
(@CGUID+27, 49008, 0, 1, 169, 0, -4882.052, -6720.606, 4.56483, 1.012291, 120, 0, 0), -- Axebite Infantry
(@CGUID+28, 49008, 0, 1, 169, 0, -4819.941, -6686.005, 4.512493, 0.3316126, 120, 0, 0), -- Axebite Infantry
(@CGUID+29, 49008, 0, 1, 169, 0, -4851.174, -6668.561, 7.951297, 1.954769, 120, 0, 0), -- Axebite Infantry
(@CGUID+30, 49008, 0, 1, 169, 0, -4810.144, -6692.25, 4.433012, 6.213372, 120, 0, 0), -- Axebite Infantry
(@CGUID+31, 49008, 0, 1, 169, 0, -4939.653, -6727.825, 5.702463, 6.248279, 120, 0, 0), -- Axebite Infantry
(@CGUID+32, 49008, 0, 1, 169, 0, -4770.608, -6711.078, 4.45895, 5.5676, 120, 0, 0), -- Axebite Infantry
(@CGUID+33, 49008, 0, 1, 169, 0, -4771.059, -6704.443, 4.412205, 5.899213, 120, 0, 0), -- Axebite Infantry
(@CGUID+34, 49008, 0, 1, 169, 0, -4810.844, -6646.46, 4.543884, 1.797689, 120, 0, 0), -- Axebite Infantry
(@CGUID+35, 49008, 0, 1, 169, 0, -4745.971, -6667.441, 4.617817, 5.986479, 120, 0, 0), -- Axebite Infantry
(@CGUID+36, 49008, 0, 1, 169, 0, -4736.069, -6665.521, 5.166455, 6.230825, 120, 0, 0), -- Axebite Infantry
(@CGUID+37, 49008, 0, 1, 169, 0, -4736.694, -6663.424, 5.110536, 0.2094395, 120, 0, 0), -- Axebite Infantry
(@CGUID+38, 49008, 0, 1, 169, 0, -4776.533, -6632.569, 4.418663, 0.5759587, 120, 0, 0), -- Axebite Infantry
(@CGUID+39, 49008, 0, 1, 169, 0, -4840.448, -6601.53, 9.500094, 2.600541, 120, 0, 0), -- Axebite Infantry
(@CGUID+40, 49008, 0, 1, 169, 0, -4847.731, -6597.38, 9.500094, 2.583087, 120, 0, 0), -- Axebite Infantry
(@CGUID+41, 49008, 0, 1, 169, 0, -4848.913, -6599.894, 9.500094, 2.076942, 120, 0, 0), -- Axebite Infantry
(@CGUID+42, 49008, 0, 1, 169, 0, -5008.031, -6812.045, -1.728834, 5.602507, 120, 0, 0), -- Axebite Infantry
(@CGUID+43, 49008, 0, 1, 169, 0, -4981.144, -6823.128, -1.560934, 5.72468, 120, 0, 0), -- Axebite Infantry
(@CGUID+44, 49008, 0, 1, 169, 0, -4922.627, -6842.366, -1.685967, 3.316126, 120, 0, 0), -- Axebite Infantry
(@CGUID+45, 49008, 0, 1, 169, 0, -4961.75, -6837.153, -1.531922, 6.213372, 120, 0, 0), -- Axebite Infantry
(@CGUID+46, 49008, 0, 1, 169, 0, -5000.25, -6832.514, -1.540749, 1.989675, 120, 0, 0), -- Axebite Infantry
(@CGUID+47, 49008, 0, 1, 169, 0, -5047.971, -6742.172, -1.612649, 5.131268, 120, 0, 0), -- Axebite Infantry
(@CGUID+48, 49008, 0, 1, 169, 0, -5044.627, -6758.557, -1.773251, 0.8552113, 120, 0, 0), -- Axebite Infantry
(@CGUID+49, 49008, 0, 1, 169, 0, -5035.184, -6775.264, -1.618659, 5.67232, 120, 0, 0), -- Axebite Infantry
(@CGUID+50, 49008, 0, 1, 169, 0, -5050.337, -6706.738, -1.727231, 1.064651, 120, 0, 0), -- Axebite Infantry
(@CGUID+51, 49008, 0, 1, 169, 0, -5054.03, -6722.918, -1.785994, 1.308997, 120, 0, 0), -- Axebite Infantry
(@CGUID+52, 49009, 0, 1, 169, 0, -4907.776, -6731.543, 0.7164544, 0.8377581, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+53, 49009, 0, 1, 169, 0, -4854.491, -6686.615, 5.995787, 1.675516, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+54, 49009, 0, 1, 169, 0, -4818.045, -6737.342, 9.500101, 5.689773, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+55, 49009, 0, 1, 169, 0, -4961.53, -6757.149, 4.700684, 3.089233, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+56, 49009, 0, 1, 169, 0, -4959.76, -6754.802, 4.666667, 3.246312, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+57, 49009, 0, 1, 169, 0, -4955.168, -6769.96, 5.421104, 1.291544, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+58, 49009, 0, 1, 169, 0, -4804.037, -6650.535, 4.448647, 2.024582, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+59, 49009, 0, 1, 169, 0, -4817.3, -6619.95, 7.013344, 2.495821, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+60, 49009, 0, 1, 169, 0, -4962.615, -6767.698, 6.316628, 0.7330383, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+61, 49009, 0, 1, 169, 0, -4974.163, -6756.333, 5.416175, 3.124139, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+62, 49009, 0, 1, 169, 0, -4979.939, -6753.259, 5.281884, 3.804818, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+63, 49009, 0, 1, 169, 0, -4974.186, -6752.128, 5.117718, 3.612832, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+64, 49020, 0, 1, 169, 0, -4850.439, -6596.811, 9.500094, 5.51524, 120, 0, 0), -- Fargo Flintlocke
(@CGUID+65, 49022, 0, 1, 169, 0, -4762.639, -6672.523, 4.454048, 2.495821, 120, 0, 0), -- Lieutenant Fawkes
(@CGUID+66, 49025, 0, 1, 169, 0, -4733.851, -6764.844, 44.57782, 2.478368, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+67, 49025, 0, 1, 169, 0, -5006.554, -6774.135, 44.4698, 1.64061, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+68, 49025, 0, 1, 169, 0, -4720.302, -6770.793, 44.81567, 5.72468, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+69, 49025, 0, 1, 169, 0, -5001.481, -6758.92, 44.4698, 4.939282, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+70, 49341, 0, 1, 169, 0, -4904.705, -6656.596, 31.99786, 3.979351, 120, 0, 0), -- Highbank Marksman
(@CGUID+71, 49341, 0, 1, 169, 0, -4800.037, -6773.465, 17.75586, 4.834562, 120, 0, 0), -- Highbank Marksman
(@CGUID+72, 49341, 0, 1, 169, 0, -4765.715, -6771.353, 17.75253, 4.991642, 120, 0, 0), -- Highbank Marksman
(@CGUID+73, 49341, 0, 1, 169, 0, -4786.927, -6770.964, 17.66897, 3.199598, 120, 0, 0), -- Highbank Marksman
(@CGUID+74, 49341, 0, 1, 169, 0, -4868.337, -6607.35, 31.9134, 2.304971, 120, 0, 0), -- Highbank Marksman
(@CGUID+75, 49341, 0, 1, 169, 0, -4906.21, -6641.944, 31.91726, 5.412406, 120, 0, 0), -- Highbank Marksman
(@CGUID+76, 49341, 0, 1, 169, 0, -4881.326, -6596.688, 31.91219, 2.264606, 120, 0, 0), -- Highbank Marksman
(@CGUID+77, 49341, 0, 1, 169, 0, -4809.083, -6576.217, 17.34796, 5.952751, 120, 0, 0), -- Highbank Marksman
(@CGUID+78, 49341, 0, 1, 169, 0, -4910.056, -6595.374, 31.99206, 2.373648, 120, 0, 0), -- Highbank Marksman
(@CGUID+79, 49341, 0, 1, 169, 0, -4849.226, -6563.472, 17.39647, 4.660029, 120, 0, 0), -- Highbank Marksman
(@CGUID+80, 49341, 0, 1, 169, 0, -4821.847, -6570.323, 17.40815, 1.047198, 120, 0, 0), -- Highbank Marksman
(@CGUID+81, 49341, 0, 1, 169, 0, -4921.393, -6629.287, 31.91347, 4.528966, 120, 0, 0), -- Highbank Marksman
(@CGUID+82, 49341, 0, 1, 169, 0, -4800.696, -6577.948, 17.43129, 1.239184, 120, 0, 0), -- Highbank Marksman
(@CGUID+83, 49341, 0, 1, 169, 0, -4713.76, -6641.471, 17.75548, 0.6981317, 120, 0, 0), -- Highbank Marksman
(@CGUID+84, 49341, 0, 1, 169, 0, -4698.115, -6707.241, 17.80357, 6.108652, 120, 0, 0), -- Highbank Marksman
(@CGUID+85, 49341, 0, 1, 169, 0, -4693.582, -6673.078, 17.79169, 0.5061455, 120, 0, 0), -- Highbank Marksman
(@CGUID+86, 49341, 0, 1, 169, 0, -4703.444, -6740.853, 17.324, 5.67232, 120, 0, 0), -- Highbank Marksman
(@CGUID+87, 49341, 0, 1, 169, 0, -4986.333, -6761.665, 44.7027, 0.296706, 120, 0, 0), -- Highbank Marksman
(@CGUID+88, 49342, 0, 1, 169, 0, -4886.281, -6707.604, 5.243135, 4.764749, 120, 0, 0), -- Highbank Guardsman
(@CGUID+89, 49342, 0, 1, 169, 0, -4876.569, -6706.232, 4.979062, 3.882104, 120, 0, 0), -- Highbank Guardsman
(@CGUID+90, 49342, 0, 1, 169, 0, -4875.525, -6715.788, 4.662216, 0.7220657, 120, 0, 0), -- Highbank Guardsman
(@CGUID+91, 49342, 0, 1, 169, 0, -4877.607, -6714.956, 4.532949, 0.7220852, 120, 0, 0), -- Highbank Guardsman
(@CGUID+92, 49342, 0, 1, 169, 0, -4875.236, -6707.721, 4.804262, 3.882395, 120, 0, 0), -- Highbank Guardsman
(@CGUID+93, 49342, 0, 1, 169, 0, -4840.88, -6702.156, 4.854588, 6.038839, 120, 0, 0), -- Highbank Guardsman
(@CGUID+94, 49342, 0, 1, 169, 0, -4811.366, -6726.056, 7.455061, 2.373648, 120, 0, 0), -- Highbank Guardsman
(@CGUID+95, 49342, 0, 1, 169, 0, -4900.699, -6701.292, 5.093423, 5.48628, 120, 0, 0), -- Highbank Guardsman
(@CGUID+96, 49342, 0, 1, 169, 0, -4904.781, -6700.305, 4.821856, 5.549376, 120, 0, 0), -- Highbank Guardsman
(@CGUID+97, 49342, 0, 1, 169, 0, -4865.755, -6688.656, 6.968502, 5.480334, 120, 0, 0), -- Highbank Guardsman
(@CGUID+98, 49342, 0, 1, 169, 0, -4821.374, -6733.881, 9.477418, 0.06756632, 120, 0, 0), -- Highbank Guardsman
(@CGUID+99, 49342, 0, 1, 169, 0, -4817.192, -6735.533, 9.477418, 0.08493628, 120, 0, 0), -- Highbank Guardsman
(@CGUID+100, 49342, 0, 1, 169, 0, -4823.991, -6724.335, 7.478768, 0.7330383, 120, 0, 0), -- Highbank Guardsman
(@CGUID+101, 49342, 0, 1, 169, 0, -4839.175, -6702.557, 4.947917, 2.9147, 120, 0, 0), -- Highbank Guardsman
(@CGUID+102, 49342, 0, 1, 169, 0, -4868.38, -6659.069, 10.93896, 5.462881, 120, 0, 0), -- Highbank Guardsman
(@CGUID+103, 49342, 0, 1, 169, 0, -4791.365, -6706.787, 5.240479, 1.710423, 120, 0, 0), -- Highbank Guardsman
(@CGUID+104, 49342, 0, 1, 169, 0, -4828.152, -6643.914, 9.286678, 3.923418, 120, 0, 0), -- Highbank Guardsman
(@CGUID+105, 49342, 0, 1, 169, 0, -4862.175, -6653.472, 10.9392, 5.340707, 120, 0, 0), -- Highbank Guardsman
(@CGUID+106, 49342, 0, 1, 169, 0, -4882.684, -6644.769, 10.93652, 2.181662, 120, 0, 0), -- Highbank Guardsman
(@CGUID+107, 49342, 0, 1, 169, 0, -4875.171, -6644.341, 10.85477, 2.259258, 120, 0, 0), -- Highbank Guardsman
(@CGUID+108, 49342, 0, 1, 169, 0, -4884.031, -6656.323, 10.93815, 1.518436, 120, 0, 0), -- Highbank Guardsman
(@CGUID+109, 49342, 0, 1, 169, 0, -4876.697, -6645.636, 10.85494, 2.259501, 120, 0, 0), -- Highbank Guardsman
(@CGUID+110, 49342, 0, 1, 169, 0, -4883.901, -6654.582, 10.93833, 4.642576, 120, 0, 0), -- Highbank Guardsman
(@CGUID+111, 49342, 0, 1, 169, 0, -4873.755, -6637.144, 10.93653, 2.478368, 120, 0, 0), -- Highbank Guardsman
(@CGUID+112, 49342, 0, 1, 169, 0, -4814.971, -6642.113, 5.723929, 0.1047198, 120, 0, 0), -- Highbank Guardsman
(@CGUID+113, 49342, 0, 1, 169, 0, -4756.418, -6714.05, 7.768574, 2.321288, 120, 0, 0), -- Highbank Guardsman
(@CGUID+114, 49342, 0, 1, 169, 0, -4755.519, -6696.524, 7.453988, 3.961897, 120, 0, 0), -- Highbank Guardsman
(@CGUID+115, 49342, 0, 1, 169, 0, -4800.522, -6623.179, 5.225997, 4.747295, 120, 0, 0), -- Highbank Guardsman
(@CGUID+116, 49342, 0, 1, 169, 0, -4742.016, -6655.908, 5.462309, 3.961897, 120, 0, 0), -- Highbank Guardsman
(@CGUID+117, 49342, 0, 1, 169, 0, -4826.598, -6617.851, 8.566182, 5.441192, 120, 0, 0), -- Highbank Guardsman
(@CGUID+118, 49342, 0, 1, 169, 0, -4825.168, -6616.511, 8.154016, 5.477563, 120, 0, 0), -- Highbank Guardsman
(@CGUID+119, 49342, 0, 1, 169, 0, -4738.507, -6673.887, 5.853456, 2.478368, 120, 0, 0), -- Highbank Guardsman
(@CGUID+120, 49342, 0, 1, 169, 0, -4743.481, -6744.045, 5.240479, 2.356194, 120, 0, 0), -- Highbank Guardsman
(@CGUID+121, 49342, 0, 1, 169, 0, -4820.243, -6612.654, 7.379973, 2.346351, 120, 0, 0), -- Highbank Guardsman
(@CGUID+122, 49342, 0, 1, 169, 0, -4821.639, -6614.076, 7.709207, 2.356194, 120, 0, 0), -- Highbank Guardsman
(@CGUID+123, 49342, 0, 1, 169, 0, -4723.26, -6660.8, 5.258198, 3.543018, 120, 0, 0), -- Highbank Guardsman
(@CGUID+124, 49342, 0, 1, 169, 0, -4704.378, -6644.24, 7.952923, 4.607669, 120, 0, 0), -- Highbank Guardsman
(@CGUID+125, 49342, 0, 1, 169, 0, -4722.024, -6756.346, 8.167795, 3.473205, 120, 0, 0), -- Highbank Guardsman
(@CGUID+126, 49342, 0, 1, 169, 0, -4983.077, -6731.653, 5.221353, 2.327248, 120, 0, 0), -- Highbank Guardsman
(@CGUID+127, 49342, 0, 1, 169, 0, -4982.356, -6752.124, 5.525763, 0.541052, 120, 0, 0), -- Highbank Guardsman
(@CGUID+128, 49342, 0, 1, 169, 0, -4983.703, -6725.988, 5.219322, 5.742133, 120, 0, 0), -- Highbank Guardsman
(@CGUID+129, 49342, 0, 1, 169, 0, -4979.617, -6732.406, 5.357412, 2.270613, 120, 0, 0), -- Highbank Guardsman
(@CGUID+130, 49343, 0, 1, 169, 0, -4886.837, -6608.656, 1.691776, 3.071779, 120, 0, 0), -- Highbank Prison Guard
(@CGUID+131, 49343, 0, 1, 169, 0, -4899.962, -6628.552, 11.00575, 3.822271, 120, 0, 0), -- Highbank Prison Guard
(@CGUID+132, 49343, 0, 1, 169, 0, -4888.41, -6608.632, 1.692902, 0.01745329, 120, 0, 0), -- Highbank Prison Guard
(@CGUID+133, 49343, 0, 1, 169, 0, -4884.689, -6615.5, 1.690678, 5.375614, 120, 0, 0), -- Highbank Prison Guard
(@CGUID+134, 49343, 0, 1, 169, 0, -4904.833, -6632.549, 10.95766, 0.6457718, 120, 0, 0), -- Highbank Prison Guard
(@CGUID+135, 49344, 0, 1, 169, 0, -4735.056, -6763.731, 44.57782, 5.51524, 120, 0, 0), -- Highbank Prison Guard
(@CGUID+136, 49344, 0, 1, 169, 0, -5006.55, -6772.502, 44.4698, 4.677482, 120, 0, 0), -- Highbank Prison Guard
(@CGUID+137, 49350, 0, 1, 169, 0, -4912.082, -6755.543, 15.34799, 4.066617, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+138, 49350, 0, 1, 169, 0, -4912.915, -6757.125, 15.34803, 0.9948376, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+139, 49350, 0, 1, 169, 0, -4923.884, -6726.795, 5.407431, 1.871382, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+140, 49350, 0, 1, 169, 0, -4940.458, -6729.863, 5.63989, 1.727876, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+141, 49350, 0, 1, 169, 0, -4932.899, -6741.071, 5.454586, 5.305801, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+142, 49350, 0, 1, 169, 0, -4924.174, -6731.894, 5.466965, 3.455752, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+143, 49350, 0, 1, 169, 0, -4925.74, -6732.766, 5.476225, 0.3839724, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+144, 49350, 0, 1, 169, 0, -4940.899, -6706.333, 14.19617, 5.550147, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+145, 49350, 0, 1, 169, 0, -4940.958, -6728.156, 5.704298, 4.799655, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+146, 49350, 0, 1, 169, 0, -4939.448, -6707.368, 13.90087, 2.338741, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+147, 49354, 0, 1, 169, 0, -4851.757, -6760.769, 12.39042, 5.183628, 120, 0, 0), -- Highbank Woodworker
(@CGUID+148, 49354, 0, 1, 169, 0, -4834.913, -6749.266, 11.62409, 4.642576, 120, 0, 0), -- Highbank Woodworker
(@CGUID+149, 49354, 0, 1, 169, 0, -4842.981, -6753.441, 11.64238, 1.850049, 120, 0, 0), -- Highbank Woodworker
(@CGUID+150, 49354, 0, 1, 169, 0, -4831.024, -6759.908, 11.64906, 5.637414, 120, 0, 0), -- Highbank Woodworker
(@CGUID+151, 49354, 0, 1, 169, 0, -4806.628, -6750.016, 12.7037, 3.700098, 120, 0, 0), -- Highbank Woodworker
(@CGUID+152, 49354, 0, 1, 169, 0, -4814.665, -6758.474, 9.500101, 4.921828, 120, 0, 0), -- Highbank Woodworker
(@CGUID+153, 49354, 0, 1, 169, 0, -4783.037, -6749.033, 11.83597, 0.4886922, 120, 0, 0), -- Highbank Woodworker
(@CGUID+154, 49354, 0, 1, 169, 0, -4793.875, -6753.448, 11.86547, 6.143559, 120, 0, 0), -- Highbank Woodworker
(@CGUID+155, 49354, 0, 1, 169, 0, -4735.556, -6702.156, 12.87715, 4.380776, 120, 0, 0), -- Highbank Woodworker
(@CGUID+156, 49354, 0, 1, 169, 0, -4729.318, -6695.554, 12.88499, 1.727876, 120, 0, 0), -- Highbank Woodworker
(@CGUID+157, 49354, 0, 1, 169, 0, -4725.353, -6719.813, 13.02115, 5.67232, 120, 0, 0), -- Highbank Woodworker
(@CGUID+158, 49354, 0, 1, 169, 0, -4717.278, -6691.403, 9.500094, 3.420845, 120, 0, 0), -- Highbank Woodworker
(@CGUID+159, 49354, 0, 1, 169, 0, -4722.999, -6706.184, 12.89981, 6.021386, 120, 0, 0), -- Highbank Woodworker
(@CGUID+160, 49366, 0, 1, 169, 0, -4769.646, -6669.738, 4.470486, 0.03490658, 120, 0, 0), -- Highbank Marksman
(@CGUID+161, 49366, 0, 1, 169, 0, -4768.675, -6666.328, 4.470482, 0.03490658, 120, 0, 0), -- Highbank Marksman
(@CGUID+162, 49366, 0, 1, 169, 0, -4769.774, -6667.554, 4.453924, 0.03490658, 120, 0, 0), -- Highbank Marksman
(@CGUID+163, 49366, 0, 1, 169, 0, -4768.62, -6668.627, 4.453924, 0.03490658, 120, 0, 0), -- Highbank Marksman
(@CGUID+164, 49366, 0, 1, 169, 0, -4769.752, -6665.057, 4.45496, 0.03490658, 120, 0, 0), -- Highbank Marksman
(@CGUID+165, 49686, 0, 1, 169, 0, -4891.307, -6599.856, 10.91657, 0.6108652, 120, 0, 0), -- Innkeeper Teresa <Innkeeper>
(@CGUID+166, 49688, 0, 1, 169, 0, -4916.222, -6621.262, 10.91657, 3.874631, 120, 0, 0), -- Innkeeper Francis <Innkeeper>
(@CGUID+167, 49689, 0, 1, 169, 0, -4878.781, -6686.499, 9.501736, 6.265732, 120, 0, 0), -- Bonnie Hennigan <Stable Master>
(@CGUID+168, 49695, 0, 1, 169, 0, -4852.063, -6610.596, 9.500094, 0.4363323, 120, 0, 0), -- Dorgan Slagfist <Blacksmith>
(@CGUID+169, 49702, 0, 1, 169, 0, -4822.54, -6580.802, 9.500094, 4.677482, 120, 0, 0), -- Frank Natale <Engineering & Mining Supplies>
(@CGUID+170, 49703, 0, 1, 169, 0, -4833.13, -6577.019, 9.500094, 3.961897, 120, 0, 0), -- Casandra Downs <Alchemy & Inscription Supplies>
(@CGUID+171, 49704, 0, 1, 169, 0, -4849.863, -6572.797, 9.500094, 2.96706, 120, 0, 0), -- Evan Silvia <Cook>
(@CGUID+172, 49705, 0, 1, 169, 0, -4860.858, -6578.276, 9.500094, 5.742133, 120, 0, 0), -- Leah Drewry <Tailoring Supplies>
(@CGUID+173, 49707, 0, 1, 169, 0, -4858.299, -6575.705, 9.500094, 5.148721, 120, 0, 0), -- Oslow Pliny <Jewelcrafting Supplies>
(@CGUID+174, 49714, 0, 1, 169, 0, -4836.952, -6593.335, 9.500094, 0.7330383, 120, 0, 0), -- Alexandra Merriweather <Leatherworking Supplies>
(@CGUID+175, 49721, 0, 1, 169, 0, -4858.271, -6601.838, 9.500094, 3.316126, 120, 0, 0), -- Frederick Zyda <Furnace Master>
(@CGUID+176, 49723, 0, 1, 169, 0, -4841.019, -6616.229, 9.500092, 0.3665192, 120, 0, 0), -- Philip O'Tool <Weapons Vendor>
(@CGUID+177, 49726, 0, 1, 169, 0, -4856.569, -6606.094, 9.500094, 3.857178, 120, 0, 0), -- Richard Maschner <Blacksmithing Supplies>
(@CGUID+178, 49729, 0, 1, 169, 0, -4798.946, -6596.738, 9.500094, 3.543018, 120, 0, 0), -- Lynn Baxter <Morale Officer>
(@CGUID+179, 49733, 0, 1, 169, 0, -4836.772, -6575.698, 9.5, 4.607669, 120, 0, 0), -- Ashley Downs <Reagents>
(@CGUID+180, 50134, 0, 1, 169, 0, -4864.368, -6584.908, 9.500094, 6.195919, 120, 0, 0), --  Senthii <Shard Trader>
(@CGUID+181, 45179, 0, 1, 169, 0, -5001.335, -6547.382, -57.77094, 2.329497, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+182, 45179, 0, 1, 169, 0, -4921.912, -6513.803, -54.41761, 1.001083, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+183, 45179, 0, 1, 169, 0, -4988.98, -6495.237, -58.33754, 2.931485, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+184, 45179, 0, 1, 169, 0, -5016.293, -6583.675, -17.31591, 3.255974, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+185, 45179, 0, 1, 169, 0, -5039.099, -6453.793, -27.30685, 4.039469, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+186, 45179, 0, 1, 169, 0, -5033.896, -6477.784, -29.34386, 1.072913, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+187, 45179, 0, 1, 169, 0, -4978.095, -6407.64, -16.1275, 1.053095, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+188, 45179, 0, 1, 169, 0, -5104.792, -6451.588, -38.54901, 1.482594, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+189, 45179, 0, 1, 169, 0, -5082.829, -6486.152, -44.72421, 3.115791, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+190, 45179, 0, 1, 169, 0, -5118.362, -6566.139, -103.5342, 4.764647, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+191, 45179, 0, 1, 169, 0, -5131.342, -6514.134, -74.6078, 4.55593, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+192, 45179, 0, 1, 169, 0, -5115.104, -6407.915, -35.4863, 3.182262, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+193, 45179, 0, 1, 169, 0, -5156.867, -6412.3, -63.52335, 1.570001, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+194, 45179, 0, 1, 169, 0, -5183.329, -6380.687, -85.48421, 4.710612, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+195, 45179, 0, 1, 169, 0, -5156.216, -6339.524, -61.17033, 6.236213, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+196, 45179, 0, 1, 169, 0, -5058.252, -6336.739, -20.85363, 1.418622, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+197, 45179, 0, 1, 169, 0, -5088.845, -6287.772, -18.13096, 3.372806, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+198, 45179, 0, 1, 169, 0, -5163.552, -6281.214, -58.17296, 0.7111935, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+199, 45179, 0, 1, 169, 0, -5120.731, -6244.249, -22.11869, 4.909456, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+200, 45179, 0, 1, 169, 0, -5057.605, -6224.957, -6.54326, 6.280499, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+201, 45179, 0, 1, 169, 0, -5022.556, -6261.122, -7.564455, 5.47293, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+202, 45179, 0, 1, 169, 0, -4998.645, -6311.094, -9.40301, 2.663538, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+203, 45179, 0, 1, 169, 0, -4973.862, -6353.576, -7.267853, 6.148729, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+204, 45179, 0, 1, 169, 0, -4900.643, -6376.871, -8.657864, 0.8997172, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+205, 45179, 0, 1, 169, 0, -4888.911, -6422.791, -19.13046, 1.699766, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+206, 45179, 0, 1, 169, 0, -4839.918, -6402.568, -19.09093, 4.171279, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+207, 45179, 0, 1, 169, 0, -4826.824, -6433.031, -27.64719, 5.404387, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+208, 45179, 0, 1, 169, 0, -4755.655, -6447.575, -25.96413, 0.1683724, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+209, 45179, 0, 1, 169, 0, -4852.952, -6481.619, -58.65791, 1.679119, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+210, 45179, 0, 1, 169, 0, -4780.755, -6514.45, -64.02144, 1.612975, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+211, 45182, 0, 1, 169, 0, -5013.121, -6515.439, -59.66002, 3.469536, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+212, 45182, 0, 1, 169, 0, -4996.354, -6513.021, -39.1628, 3.300098, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+213, 45182, 0, 1, 169, 0, -4983.426, -6522.273, -67.97115, 3.89471, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+214, 45182, 0, 1, 169, 0, -5061.076, -6435.584, -28.63995, 2.470706, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+215, 45182, 0, 1, 169, 0, -5073.78, -6413.625, -28.9705, 3.078883, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+216, 45182, 0, 1, 169, 0, -5106.088, -6463.164, -41.31903, 1.430817, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+217, 45182, 0, 1, 169, 0, -5047.81, -6414.341, -17.40916, 4.695654, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+218, 45182, 0, 1, 169, 0, -5039.889, -6380.367, -20.32251, 4.40887, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+219, 45182, 0, 1, 169, 0, -5032.801, -6404.697, -24.28627, 1.773059, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+220, 45182, 0, 1, 169, 0, -5141.111, -6479.861, -52.2795, 1.860383, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+221, 45182, 0, 1, 169, 0, -5134.693, -6465.79, -52.8449, 1.229326, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+222, 45182, 0, 1, 169, 0, -5156.046, -6475.646, -66.75235, 4.471229, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+223, 45182, 0, 1, 169, 0, -5131.297, -6418.354, -51.18985, 1.113275, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+224, 45182, 0, 1, 169, 0, -5160.839, -6387.738, -52.2793, 0.1249797, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+225, 45182, 0, 1, 169, 0, -5126.563, -6324.405, -52.13245, 1.570796, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+226, 45182, 0, 1, 169, 0, -5162.682, -6316.993, -58.53597, 4.904778, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+227, 45182, 0, 1, 169, 0, -5133.911, -6298.42, -55.447, 4.206748, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+228, 45182, 0, 1, 169, 0, -5113.354, -6310.522, -29.0166, 2.850987, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+229, 45182, 0, 1, 169, 0, -5148.751, -6269.469, -53.10834, 4.29352, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+230, 45182, 0, 1, 169, 0, -5111.7, -6254.893, -22.0977, 5.734427, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+231, 45182, 0, 1, 169, 0, -5059.858, -6257.576, -9.782834, 3.194503, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+232, 45182, 0, 1, 169, 0, -4999.985, -6259.037, -2.275794, 5.964628, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+233, 45182, 0, 1, 169, 0, -5020.92, -6319.648, -15.1071, 3.587889, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+234, 45182, 0, 1, 169, 0, -4975.583, -6340.968, -5.616241, 5.293905, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+235, 45182, 0, 1, 169, 0, -4938.457, -6340.718, -4.43966, 5.269808, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+236, 45182, 0, 1, 169, 0, -4959.4, -6384.83, -13.61697, 5.386121, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+237, 45182, 0, 1, 169, 0, -4891.859, -6401.261, -15.53361, 5.737289, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+238, 45182, 0, 1, 169, 0, -4923.441, -6405.55, -6.339195, 5.272691, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+239, 45182, 0, 1, 169, 0, -4838.521, -6378.976, -11.87418, 5.126206, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+240, 45182, 0, 1, 169, 0, -4786.602, -6510.793, -65.95833, 5.600965, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+241, 45182, 0, 1, 169, 0, -4884.78, -6488.579, -60.99342, 3.713374, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+242, 45210, 0, 1, 169, 0, -4953.95, -6440.61, 0.2519073, 6.091199, 120, 0, 0), -- Stranded Crewman
(@CGUID+243, 45210, 0, 1, 169, 0, -4966.3, -6451.35, 2.042363, 4.310963, 120, 0, 0), -- Stranded Crewman
(@CGUID+244, 45210, 0, 1, 169, 0, -4937.11, -6446.54, 3.121446, 5.320683, 120, 0, 0), -- Stranded Crewman
(@CGUID+245, 45210, 0, 1, 169, 0, -4971.294, -6436.867, 0.3008443, 0.6401017, 120, 0, 0), -- Stranded Crewman
(@CGUID+246, 45224, 0, 1, 169, 0, -4958.87, -6442.9, 3.590053, 3.769911, 120, 0, 0), -- Lashed to the Mast "Bunny"
(@CGUID+247, 45171, 0, 1, 169, 0, -4966.12, -6441.25, 1.075496, 4.502949, 120, 0, 0); -- Ephram Hardstone

UPDATE `creature_template` SET `flags_extra`=128, `InhabitType`=4 WHERE `entry` IN (45224,45256);

DELETE FROM `creature_template_addon` WHERE `entry` IN (45182,49350,49354,49342);
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(45182,0,1,0, '12544'),(49350,0,256,0, '10022'),(49354,0,257,234, ''),(49342,0,256,0, '');

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+15 AND @CGUID+63;
INSERT INTO `creature_addon` (`guid`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(@CGUID+15,65536,1,0, '84020 86378'),(@CGUID+16,65536,1,0, '84020 29266'),(@CGUID+17,65536,1,0, '84020 29266'),
(@CGUID+18,65536,1,0, '84020 29266'),(@CGUID+19,65536,1,0, '84020 29266'),(@CGUID+20,65536,1,0, '84020 29266'),
(@CGUID+21,65536,1,0, '84020 86378'),(@CGUID+22,65536,1,0, '84020 29266'),(@CGUID+23,65536,1,0, '84020 29266'),
(@CGUID+24,65536,1,0, '84020 86378'),(@CGUID+25,65536,1,0, '84020 29266'),(@CGUID+26,65536,1,0, '84020 29266'),
(@CGUID+27,65536,1,0, '84020 86378'),(@CGUID+28,65536,1,0, '84020 29266'),(@CGUID+29,65536,1,0, '84020 29266'),
(@CGUID+30,65536,1,0, '84020 86378'),(@CGUID+31,65536,1,0, '84020 86378'),(@CGUID+32,65536,1,0, '84020 29266'),
(@CGUID+33,65536,1,0, '84020 29266'),(@CGUID+34,65536,1,0, '84020 29266'),(@CGUID+35,65536,1,0, '84020 29266'),
(@CGUID+36,65536,1,0, '84020 29266'),(@CGUID+37,65536,1,0, '84020 29266'),(@CGUID+38,65536,1,0, '84020 29266'),
(@CGUID+39,65536,1,0, '84020 86378'),(@CGUID+40,65536,1,0, '84020 29266'),(@CGUID+41,65536,1,0, '84020 29266'),
(@CGUID+42,65536,1,0, '84020 29266'),(@CGUID+43,65536,1,0, '84020 29266'),(@CGUID+44,65536,1,0, '84020 29266'),
(@CGUID+45,65536,1,0, '84020 29266'),(@CGUID+46,65536,1,0, '84020 29266'),(@CGUID+47,65536,1,0, '84020 29266'),
(@CGUID+48,65536,1,0, '84020 29266'),(@CGUID+49,65536,1,0, '84020 29266'),(@CGUID+50,65536,1,0, '84020 29266'),
(@CGUID+51,65536,1,0, '84020 29266'),(@CGUID+52,65536,1,0, '84020 29266'),(@CGUID+53,65536,1,0, '84020 29266'),
(@CGUID+54,65536,1,0, '84020 29266'),(@CGUID+55,65536,1,0, '84020 86378'),(@CGUID+56,65536,1,0, '84020 86378'),
(@CGUID+57,65536,1,0, '84020 29266'),(@CGUID+58,65536,1,0, '84020 29266'),(@CGUID+59,65536,1,0, '84020 29266'),
(@CGUID+60,65536,1,0, '84020 29266'),(@CGUID+61,65536,1,0, '84020 29266'),(@CGUID+62,65536,1,0, '84020 86378'),
(@CGUID+63,65536,1,0, '84020 29266');

DELETE FROM `spell_script_names` WHERE `spell_id`=86378;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (86378,'spell_gen_creature_permanent_feign_death');

-- Spell Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (82405);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,82405,0,31,5,205248,0,0,'','Spell 82405 targets gameobject entry 205248');

-- SAI for Highbank Shaman
SET @ENTRY := 45869;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,600000,600000,11,79892,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highbank Shaman - OOC - Cast 'Water Shield'"),
(@ENTRY,0,1,0,1,0,100,0,1000,8000,15000,18000,11,82405,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highbank Shaman - OOC - Cast 'Cosmetic - Chain Lightning (single)(long pre-cast)'");

-- Highbank, Twilight Highlands, Alliance Zone questing start area
DELETE FROM `phase_area` WHERE `AreaId` IN (5140,5424) AND `PhaseId` IN (169,361);
INSERT INTO `phase_area` (`AreaId`,`PhaseId`,`Comment`) VALUES 
(5140,361, 'Highbank phase before quest 28598 complete'),
(5140,169, 'Highbank phase after quest 28598 complete'),
(5424,361, 'Obsidian Breakers phase before quest 28598 complete'),
(5424,169, 'Obsidian Breakers phase after quest 28598 complete');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceEntry` IN (5140,5424);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(26,361,5140,0,1, 8,0,28598,0,0,1,0,0,'','Set phase 361 in area 5140 if quest 28598 not rewarded'),
(26,361,5140,0,2,28,0,28598,0,0,1,0,0,'','Set phase 361 in area 5140 if quest 28598 not complete'),
(26,169,5140,0,1, 8,0,28598,0,0,0,0,0,'','Set phase 169 in area 5140 if quest 28598 rewarded'),
(26,169,5140,0,2,28,0,28598,0,0,0,0,0,'','Set phase 169 in area 5140 if quest 28598 complete'),
(26,361,5424,0,1, 8,0,28598,0,0,1,0,0,'','Set phase 361 in area 5140 if quest 28598 not rewarded'),
(26,361,5424,0,2,28,0,28598,0,0,1,0,0,'','Set phase 361 in area 5140 if quest 28598 not complete'),
(26,169,5424,0,1, 8,0,28598,0,0,0,0,0,'','Set phase 169 in area 5140 if quest 28598 rewarded'),
(26,169,5424,0,2,28,0,28598,0,0,0,0,0,'','Set phase 169 in area 5140 if quest 28598 complete');

-- Pathing for Highbank Guardsman Entry: 49342 'TDB FORMAT' 
SET @NPC := @CGUID+104;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4831.354,`position_y`=-6647.092,`position_z`=9.453926 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,256,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4831.354,-6647.092,9.453926,0,0,0,0,100,0),
(@PATH,2,-4822.372,-6638.174,8.984688,0,0,0,0,100,0),
(@PATH,3,-4831.354,-6647.092,9.453926,0,0,0,0,100,0),
(@PATH,4,-4847.052,-6662.674,8.521555,0,0,0,0,100,0),
(@PATH,5,-4865.58,-6678.872,8.742817,0,0,0,0,100,0),
(@PATH,6,-4885.455,-6696.389,9.495326,0,0,0,0,100,0),
(@PATH,7,-4865.58,-6678.872,8.742817,0,0,0,0,100,0),
(@PATH,8,-4847.052,-6662.674,8.521555,0,0,0,0,100,0);

-- Pathing for Highbank Guardsman Entry: 49342 'TDB FORMAT' 
SET @NPC := @CGUID+89;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4844.736,`position_y`=-6675.703,`position_z`=6.371723 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4845.399,`position_y`=-6677.637,`position_z`=6.146143 WHERE `guid`=@CGUID+90;
DELETE FROM `creature_addon` WHERE `guid` IN (@NPC,@CGUID+90);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,256,0, ''),(@CGUID+90,@PATH,0,0,256,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4844.736,-6675.703,6.371723,0,0,0,0,100,0),
(@PATH,2,-4812.865,-6687.143,5.097479,0,0,0,0,100,0),
(@PATH,3,-4788.882,-6696.946,4.453924,0,0,0,0,100,0),
(@PATH,4,-4772.415,-6714.198,4.449464,0,0,0,0,100,0),
(@PATH,5,-4753.194,-6735.156,5.183077,0,0,0,0,100,0),
(@PATH,6,-4772.415,-6714.198,4.449464,0,0,0,0,100,0),
(@PATH,7,-4788.882,-6696.946,4.453924,0,0,0,0,100,0),
(@PATH,8,-4812.865,-6687.143,5.097479,0,0,0,0,100,0),
(@PATH,9,-4844.736,-6675.703,6.371723,0,0,0,0,100,0),
(@PATH,10,-4859.772,-6663.365,8.605051,0,0,0,0,100,0),
(@PATH,11,-4866.864,-6654.434,10.85385,0,0,0,0,100,0),
(@PATH,12,-4879.003,-6639.686,10.85162,0,0,0,0,100,0),
(@PATH,13,-4866.943,-6654.337,10.85399,0,0,0,0,100,0),
(@PATH,14,-4859.375,-6663.541,8.605051,0,0,0,0,100,0);
-- Highbank Guardsman formation
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (@NPC);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,2,0,0),
(@NPC,@CGUID+90,2,90,2,5,12);

-- Pathing for Highbank Guardsman Entry: 49342 'TDB FORMAT' 
SET @NPC := @CGUID+91;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4829.724,`position_y`=-6701.387,`position_z`=5.203925 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4829.152,`position_y`=-6704.967,`position_z`=5.165596 WHERE `guid`=@CGUID+92;
DELETE FROM `creature_addon` WHERE `guid` IN (@NPC,@CGUID+92);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,256,0, ''),(@CGUID+92,@PATH,0,0,256,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4829.724,-6701.387,5.203925,0,0,0,0,100,0),
(@PATH,2,-4820.585,-6711.351,5.203925,0,0,0,0,100,0),
(@PATH,3,-4829.724,-6701.387,5.203925,0,0,0,0,100,0),
(@PATH,4,-4840.894,-6694.573,4.462788,0,0,0,0,100,0),
(@PATH,5,-4856.132,-6699.838,4.462788,0,0,0,0,100,0),
(@PATH,6,-4874.393,-6714.79,4.677069,0,0,0,0,100,0),
(@PATH,7,-4883.927,-6723.188,4.552069,0,0,0,0,100,0),
(@PATH,8,-4874.393,-6714.79,4.677069,0,0,0,0,100,0),
(@PATH,9,-4856.132,-6699.838,4.462788,0,0,0,0,100,0),
(@PATH,10,-4840.894,-6694.573,4.462788,0,0,0,0,100,0);
-- Highbank Guardsman formation
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (@NPC);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,2,0,0),
(@NPC,@CGUID+92,2,90,2,2,7);

-- Pathing for Highbank Guardsman Entry: 49342 'TDB FORMAT' 
SET @NPC := @CGUID+95;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4942.741,`position_y`=-6752.318,`position_z`=0.8641129 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4941.295,`position_y`=-6753.615,`position_z`=0.8641129 WHERE `guid`=@CGUID+96;
DELETE FROM `creature_addon` WHERE `guid` IN (@NPC,@CGUID+96);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,256,0, ''),(@CGUID+96,@PATH,0,0,256,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4942.741,-6752.318,0.8641129,0,0,0,0,100,0),
(@PATH,2,-4932.917,-6746.643,1.33007,0,0,0,0,100,0),
(@PATH,3,-4926.818,-6742.708,5.499268,0,0,0,0,100,0),
(@PATH,4,-4918.39,-6736.981,5.506974,0,0,0,0,100,0),
(@PATH,5,-4912.44,-6732.709,1.218719,0,0,0,0,100,0),
(@PATH,6,-4902.538,-6725.488,0.6599402,0,0,0,0,100,0),
(@PATH,7,-4893.75,-6718.75,4.802069,0,0,0,0,100,0),
(@PATH,8,-4891.918,-6710.278,5.177069,0,0,0,0,100,0),
(@PATH,9,-4903.537,-6698.389,5.066396,0,0,0,0,100,0),
(@PATH,10,-4911.208,-6692.064,4.923329,0,0,0,0,100,0),
(@PATH,11,-4903.537,-6698.389,5.066396,0,0,0,0,100,0),
(@PATH,12,-4891.918,-6710.278,5.177069,0,0,0,0,100,0),
(@PATH,13,-4893.681,-6719.577,4.765448,0,0,0,0,100,0),
(@PATH,14,-4902.229,-6725.37,0.8312815,0,0,0,0,100,0),
(@PATH,15,-4912.288,-6732.601,1.135311,0,0,0,0,100,0),
(@PATH,16,-4918.236,-6736.877,5.478069,0,0,0,0,100,0),
(@PATH,17,-4926.818,-6742.708,5.499268,0,0,0,0,100,0),
(@PATH,18,-4932.897,-6746.656,1.334893,0,0,0,0,100,0),
(@PATH,19,-4942.05,-6752.148,0.8669548,0,0,0,0,100,0),
(@PATH,20,-4950.085,-6756.993,4.960552,0,0,0,0,100,0),
(@PATH,21,-4962.073,-6764.293,5.762395,0,0,0,0,100,0),
(@PATH,22,-4950.085,-6756.993,4.960552,0,0,0,0,100,0);
-- Highbank Guardsman formation
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (@NPC);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,2,0,0),
(@NPC,@CGUID+96,2,90,2,10,21);

-- Pathing for Highbank Guardsman Entry: 49342 'TDB FORMAT' 
SET @NPC := @CGUID+98;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4805.575,`position_y`=-6734.543,`position_z`=9.477418 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4804.171,`position_y`=-6735.854,`position_z`=9.413300 WHERE `guid`=@CGUID+99;
DELETE FROM `creature_addon` WHERE `guid` IN (@NPC,@CGUID+99);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,256,0, ''),(@CGUID+99,@PATH,0,0,256,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4805.575,-6734.543,9.477418,0,0,0,0,100,0),
(@PATH,2,-4791.366,-6724.941,9.449464,0,0,0,0,100,0),
(@PATH,3,-4805.575,-6734.543,9.477418,0,0,0,0,100,0),
(@PATH,4,-4825.314,-6736.224,9.477418,0,0,0,0,100,0),
(@PATH,5,-4848.965,-6737.738,9.509106,0,0,0,0,100,0),
(@PATH,6,-4861.397,-6745.403,9.509106,0,0,0,0,100,0),
(@PATH,7,-4848.965,-6737.738,9.509106,0,0,0,0,100,0),
(@PATH,8,-4825.314,-6736.224,9.477418,0,0,0,0,100,0);
-- Highbank Guardsman formation
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (@NPC);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,2,0,0),
(@NPC,@CGUID+99,2,90,2,2,6);

-- Pathing for Highbank Guardsman Entry: 49342 'TDB FORMAT' 
SET @NPC := @CGUID+107;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4810.429,`position_y`=-6649.76,`position_z`=4.453927 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4809.291,`position_y`=-6650.98,`position_z`=4.349684 WHERE `guid`=@CGUID+109;
DELETE FROM `creature_addon` WHERE `guid` IN (@NPC,@CGUID+109);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,256,0, ''),(@CGUID+109,@PATH,0,0,256,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4810.429,-6649.76,4.453927,0,0,0,0,100,0),
(@PATH,2,-4800.365,-6638.535,4.453927,0,0,0,0,100,0),
(@PATH,3,-4776.257,-6640.082,4.453927,0,0,0,0,100,0),
(@PATH,4,-4757.394,-6654.349,4.879866,0,0,0,0,100,0),
(@PATH,5,-4755.499,-6674.507,4.703925,0,0,0,0,100,0),
(@PATH,6,-4764.674,-6687.894,4.850165,0,0,0,0,100,0),
(@PATH,7,-4782.018,-6699.934,4.453924,0,0,0,0,100,0),
(@PATH,8,-4803.651,-6699.425,4.453925,0,0,0,0,100,0),
(@PATH,9,-4822.853,-6692.899,4.453925,0,0,0,0,100,0),
(@PATH,10,-4803.651,-6699.425,4.453925,0,0,0,0,100,0),
(@PATH,11,-4782.018,-6699.934,4.453924,0,0,0,0,100,0),
(@PATH,12,-4764.674,-6687.894,4.850165,0,0,0,0,100,0),
(@PATH,13,-4755.499,-6674.507,4.703925,0,0,0,0,100,0),
(@PATH,14,-4757.394,-6654.349,4.879866,0,0,0,0,100,0),
(@PATH,15,-4776.257,-6640.082,4.453927,0,0,0,0,100,0),
(@PATH,16,-4800.365,-6638.535,4.453927,0,0,0,0,100,0),
(@PATH,17,-4810.429,-6649.76,4.453927,0,0,0,0,100,0),
(@PATH,18,-4821.266,-6666.986,4.592597,0,0,0,0,100,0),
(@PATH,19,-4841.323,-6682.993,5.087299,0,0,0,0,100,0),
(@PATH,20,-4859.896,-6695.778,4.781879,0,0,0,0,100,0),
(@PATH,21,-4879.359,-6711.797,4.659491,0,0,0,0,100,0),
(@PATH,22,-4859.896,-6695.778,4.781879,0,0,0,0,100,0),
(@PATH,23,-4841.323,-6682.993,5.087299,0,0,0,0,100,0),
(@PATH,24,-4821.266,-6666.986,4.592597,0,0,0,0,100,0);
-- Highbank Guardsman formation
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (@NPC);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,2,0,0),
(@NPC,@CGUID+109,2,90,2,9,21);

-- Pathing for Highbank Guardsman Entry: 49342 'TDB FORMAT' 
SET @NPC := @CGUID+117;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4827.467,`position_y`=-6616.877,`position_z`=8.699944 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4826.091,`position_y`=-6615.888,`position_z`=8.375416 WHERE `guid`=@CGUID+118;
DELETE FROM `creature_addon` WHERE `guid` IN (@NPC,@CGUID+118);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,256,0, ''),(@CGUID+118,@PATH,0,0,256,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4827.467,-6616.877,8.699944,0,0,0,0,100,0),
(@PATH,2,-4841.932,-6603.295,9.491281,0,0,0,0,100,0),
(@PATH,3,-4855.537,-6591.938,9.492112,0,0,0,0,100,0),
(@PATH,4,-4855.488,-6583.986,9.492112,0,0,0,0,100,0),
(@PATH,5,-4846.953,-6580.429,9.492112,0,0,0,0,100,0),
(@PATH,6,-4835.45,-6585.078,9.492112,0,0,0,0,100,0),
(@PATH,7,-4812.111,-6595.083,9.486526,0,0,0,0,100,0),
(@PATH,8,-4799.677,-6601.488,9.430349,0,0,0,0,100,0),
(@PATH,9,-4812.111,-6595.083,9.486526,0,0,0,0,100,0),
(@PATH,10,-4835.45,-6585.078,9.492112,0,0,0,0,100,0),
(@PATH,11,-4846.953,-6580.429,9.492112,0,0,0,0,100,0),
(@PATH,12,-4855.488,-6583.986,9.492112,0,0,0,0,100,0),
(@PATH,13,-4855.537,-6591.938,9.492112,0,0,0,0,100,0),
(@PATH,14,-4841.932,-6603.295,9.491281,0,0,0,0,100,0),
(@PATH,15,-4827.467,-6616.877,8.699944,0,0,0,0,100,0),
(@PATH,16,-4811.299,-6635.024,5.606759,0,0,0,0,100,0);
-- Highbank Guardsman formation
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (@NPC);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,2,0,0),
(@NPC,@CGUID+118,2,90,2,8,16);

-- Pathing for Highbank Guardsman Entry: 49342 'TDB FORMAT' 
SET @NPC := @CGUID+121;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4802.412,`position_y`=-6630.389,`position_z`=4.89843 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4800.862,`position_y`=-6628.632,`position_z`=4.97909 WHERE `guid`=@CGUID+122;
DELETE FROM `creature_addon` WHERE `guid` IN (@NPC,@CGUID+122);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,256,0, ''),(@CGUID+122,@PATH,0,0,256,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4802.412,-6630.389,4.89843,0,0,0,0,100,0),
(@PATH,2,-4821.561,-6611.309,7.657464,0,0,0,0,100,0),
(@PATH,3,-4802.412,-6630.389,4.89843,0,0,0,0,100,0),
(@PATH,4,-4778.92,-6632.299,4.430349,0,0,0,0,100,0),
(@PATH,5,-4764.863,-6643.139,4.840559,0,0,0,0,100,0),
(@PATH,6,-4746.21,-6659.58,5.030501,0,0,0,0,100,0),
(@PATH,7,-4737.21,-6665.137,5.079817,0,0,0,0,100,0),
(@PATH,8,-4746.21,-6659.58,5.030501,0,0,0,0,100,0),
(@PATH,9,-4764.863,-6643.139,4.840559,0,0,0,0,100,0),
(@PATH,10,-4778.92,-6632.299,4.430349,0,0,0,0,100,0);
-- Highbank Guardsman formation
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (@NPC);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,2,0,0),
(@NPC,@CGUID+122,2,90,2,2,7);

-- Pathing for Highbank Guardsman Entry: 49342 'TDB FORMAT' 
SET @NPC := @CGUID+126;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4999.344,`position_y`=-6721.851,`position_z`=5.03057 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4998.414,`position_y`=-6720.321,`position_z`=5.03057 WHERE `guid`=@CGUID+129;
DELETE FROM `creature_addon` WHERE `guid` IN (@NPC,@CGUID+129);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,256,0, ''),(@CGUID+129,@PATH,0,0,256,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4999.344,-6721.851,5.03057,0,0,0,0,100,0),
(@PATH,2,-5012.5,-6715.625,5.228971,0,0,0,0,100,0),
(@PATH,3,-4999.344,-6721.851,5.03057,0,0,0,0,100,0),
(@PATH,4,-4984.026,-6730.647,5.224112,0,0,0,0,100,0),
(@PATH,5,-4974.79,-6740.434,5.197261,0,0,0,0,100,0),
(@PATH,6,-4967.141,-6754.606,4.469234,0,0,0,0,100,0),
(@PATH,7,-4974.79,-6740.434,5.197261,0,0,0,0,100,0),
(@PATH,8,-4984.026,-6730.647,5.224112,0,0,0,0,100,0);
-- Highbank Guardsman formation
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (@NPC);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,2,0,0),
(@NPC,@CGUID+129,2,90,2,2,6);

-- Pathing for Highbank Marksman Entry: 49341 'TDB FORMAT' 
SET @NPC := @CGUID+73;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4752.351,`position_y`=-6768.917,`position_z`=17.66694 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4752.351,-6768.917,17.66694,0,0,0,0,100,0),
(@PATH,2,-4777.759,-6770.432,17.66796,0,0,0,0,100,0),
(@PATH,3,-4795.939,-6771.488,17.67006,0,0,0,0,100,0),
(@PATH,4,-4806.658,-6772.037,17.67183,0,0,0,0,100,0),
(@PATH,5,-4795.939,-6771.488,17.67006,0,0,0,0,100,0),
(@PATH,6,-4777.759,-6770.432,17.66796,0,0,0,0,100,0);

-- Pathing for Highbank Marksman Entry: 49341 'TDB FORMAT' 
SET @NPC := @CGUID+74;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4868.479,`position_y`=-6607.193,`position_z`=31.9134 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4868.479,-6607.193,31.9134,0,0,0,0,100,0),
(@PATH,2,-4861,-6615.479,31.91307,0,0,0,0,100,0),
(@PATH,3,-4856.319,-6620.979,31.91303,0,0,0,0,100,0),
(@PATH,4,-4861,-6615.479,31.91307,0,0,0,0,100,0),
(@PATH,5,-4868.479,-6607.193,31.9134,0,0,0,0,100,0),
(@PATH,6,-4875.474,-6598.662,31.91329,0,0,0,0,100,0);

-- Pathing for Highbank Marksman Entry: 49341 'TDB FORMAT' 
SET @NPC := @CGUID+75;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4894.912,`position_y`=-6654.983,`position_z`=31.91327 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4894.912,-6654.983,31.91327,0,0,0,0,100,0),
(@PATH,2,-4902.002,-6646.939,31.91708,0,0,0,0,100,0),
(@PATH,3,-4908.319,-6639.439,31.91735,0,0,0,0,100,0),
(@PATH,4,-4913.731,-6632.486,31.91758,0,0,0,0,100,0),
(@PATH,5,-4908.319,-6639.439,31.91735,0,0,0,0,100,0),
(@PATH,6,-4902.002,-6646.939,31.91708,0,0,0,0,100,0);

-- Pathing for Highbank Marksman Entry: 49341 'TDB FORMAT' 
SET @NPC := @CGUID+76;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4872.212,`position_y`=-6607.646,`position_z`=31.9121 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4872.212,-6607.646,31.9121,0,0,0,0,100,0),
(@PATH,2,-4863.476,-6618.691,31.91529,0,0,0,0,100,0),
(@PATH,3,-4856.575,-6626.837,31.91225,0,0,0,0,100,0),
(@PATH,4,-4855.668,-6635.78,31.91225,0,0,0,0,100,0),
(@PATH,5,-4867.497,-6646.087,31.91334,0,0,0,0,100,0),
(@PATH,6,-4878.448,-6655,31.91417,0,0,0,0,100,0),
(@PATH,7,-4886.877,-6661.175,31.91277,0,0,0,0,100,0),
(@PATH,8,-4892.356,-6660.978,31.91396,0,0,0,0,100,0),
(@PATH,9,-4898.309,-6665.531,31.91474,0,0,0,0,100,0),
(@PATH,10,-4892.356,-6660.978,31.91396,0,0,0,0,100,0),
(@PATH,11,-4886.877,-6661.175,31.91277,0,0,0,0,100,0),
(@PATH,12,-4878.448,-6655,31.91417,0,0,0,0,100,0),
(@PATH,13,-4867.497,-6646.087,31.91334,0,0,0,0,100,0),
(@PATH,14,-4855.668,-6635.78,31.91225,0,0,0,0,100,0),
(@PATH,15,-4856.56,-6626.986,31.91182,0,0,0,0,100,0),
(@PATH,16,-4863.476,-6618.691,31.91529,0,0,0,0,100,0),
(@PATH,17,-4872.212,-6607.646,31.9121,0,0,0,0,100,0),
(@PATH,18,-4882.484,-6595.295,31.91267,0,0,0,0,100,0);

-- Pathing for Highbank Marksman Entry: 49341 'TDB FORMAT' 
SET @NPC := @CGUID+77;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4814.499,`position_y`=-6574.359,`position_z`=17.34797 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4814.499,-6574.359,17.34797,0,0,0,0,100,0),
(@PATH,2,-4830.95,-6568.486,17.34797,0,0,0,0,100,0),
(@PATH,3,-4849.655,-6562.24,17.34797,0,0,0,0,100,0),
(@PATH,4,-4867.071,-6565.984,17.31609,0,0,0,0,100,0),
(@PATH,5,-4873.108,-6571.03,17.31152,0,0,0,0,100,0),
(@PATH,6,-4867.071,-6565.984,17.31609,0,0,0,0,100,0),
(@PATH,7,-4849.655,-6562.24,17.34797,0,0,0,0,100,0),
(@PATH,8,-4830.95,-6568.486,17.34797,0,0,0,0,100,0),
(@PATH,9,-4814.499,-6574.359,17.34797,0,0,0,0,100,0),
(@PATH,10,-4796.825,-6580.422,17.34795,0,0,0,0,100,0);

-- Pathing for Highbank Marksman Entry: 49341 'TDB FORMAT' 
SET @NPC := @CGUID+81;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4899.559,`position_y`=-6656.002,`position_z`=31.917 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4899.559,-6656.002,31.917,0,0,0,0,100,0),
(@PATH,2,-4906.535,-6647.281,31.9173,0,0,0,0,100,0),
(@PATH,3,-4921.559,-6630.184,31.91302,0,0,0,0,100,0),
(@PATH,4,-4920.073,-6622.172,31.91601,0,0,0,0,100,0),
(@PATH,5,-4908.894,-6612.103,31.91398,0,0,0,0,100,0),
(@PATH,6,-4894.991,-6600.474,31.91323,0,0,0,0,100,0),
(@PATH,7,-4908.894,-6612.103,31.91398,0,0,0,0,100,0),
(@PATH,8,-4920.021,-6621.894,31.91285,0,0,0,0,100,0),
(@PATH,9,-4921.559,-6630.184,31.91302,0,0,0,0,100,0),
(@PATH,10,-4906.535,-6647.281,31.9173,0,0,0,0,100,0);

-- Pathing for Tidebreaker Sailor Entry: 49350 'TDB FORMAT' 
SET @NPC := @CGUID+139;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4916.596,`position_y`=-6758.026,`position_z`=15.16407 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '10022');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4916.596,-6758.026,15.16407,0,0,0,0,100,0),
(@PATH,2,-4912.545,-6760.342,15.27375,0,0,0,0,100,0),
(@PATH,3,-4907.95,-6757.035,15.26457,0,0,0,0,100,0),
(@PATH,4,-4908.052,-6752.005,15.04875,0,0,0,0,100,0),
(@PATH,5,-4913.198,-6744.113,5.743296,0,0,0,0,100,0),
(@PATH,6,-4917.557,-6740.516,5.618814,0,0,0,0,100,0),
(@PATH,7,-4921.772,-6733.608,5.400787,0,0,0,0,100,0),
(@PATH,8,-4924.233,-6725.67,5.408527,0,0,0,0,100,0),
(@PATH,9,-4931.953,-6720.342,5.764146,0,0,0,0,100,0),
(@PATH,10,-4937.172,-6723.889,5.802237,0,0,0,0,100,0),
(@PATH,11,-4935.738,-6732.66,5.41413,0,0,0,0,100,0),
(@PATH,12,-4927.858,-6738.804,5.406329,0,0,0,0,100,0),
(@PATH,13,-4923.878,-6745.213,5.609965,0,0,0,0,100,0),
(@PATH,14,-4922.071,-6750.428,5.752007,0,0,0,0,100,0);

-- Pathing for Stranded Crewman Entry: 45210 'TDB FORMAT' 
SET @NPC := @CGUID+242;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4953.95,`position_y`=-6440.61,`position_z`=0.2519073 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4953.95,-6440.61,0.2519073,3.001966,8000,0,491,100,0),
(@PATH,2,-4953.95,-6440.61,0.2519073,6.091199,4000,0,0,100,0); 

-- Pathing for Stranded Crewman Entry: 45210 'TDB FORMAT' 
SET @NPC := @CGUID+243;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4966.3,`position_y`=-6451.35,`position_z`=2.042363 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4966.3,-6451.35,2.042363,1.117011,15000,0,0,100,0),
(@PATH,2,-4966.3,-6451.35,2.042363,4.310963,15000,0,0,100,0);

-- Pathing for Stranded Crewman Entry: 45210 'TDB FORMAT' 
SET @NPC := @CGUID+244;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4940.24,`position_y`=-6441.02,`position_z`=2.360719 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4940.24,-6441.02,2.360719,0,0,0,0,100,0),
(@PATH,2,-4941.71,-6439.77,2.094354,0,6000,0,0,100,0),
(@PATH,3,-4938.75,-6435.98,2.411006,0,0,0,0,100,0),
(@PATH,4,-4938.75,-6435.98,2.411006,1.308997,10000,0,491,100,0),
(@PATH,5,-4938.83,-6444.07,2.730427,0,0,0,0,100,0),
(@PATH,6,-4937.11,-6446.54,3.121446,0,6000,0,492,100,0);

-- Pathing for Stranded Crewman Entry: 45210 'TDB FORMAT' 
SET @NPC := @CGUID+245;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4971.13,`position_y`=-6436.74,`position_z`=0.303665 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4971.13,-6436.74,0.303665,0,0,0,0,100,0),
(@PATH,2,-4974.63,-6439.35,0.2362317,0,0,0,0,100,0),
(@PATH,3,-4974.63,-6439.35,0.2362317,5.532694,4000,0,0,100,0),
(@PATH,4,-4969.66,-6435.65,0.3125727,0,0,0,0,100,0),
(@PATH,5,-4967.47,-6433.57,0.2708609,0,0,0,0,100,0),
(@PATH,6,-4967.47,-6433.57,0.2708609,2.007129,16000,0,0,100,0);

DELETE FROM `waypoint_scripts` WHERE `id` IN (491,492);
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`dataint`,`x`,`y`,`z`,`o`,`guid`) VALUES
(491,1,1,432,0,0,0,0,0,894),
(491,4,1,432,0,0,0,0,0,895),
(492,2,1,22,0,0,0,0,0,896);

DELETE FROM `npc_vendor` WHERE `entry` IN (49695, 49726, 49729, 50381, 50382, 50134, 49733, 49702, 49703, 50386, 49704, 49705, 49707, 49714, 50458, 49723);
INSERT INTO `npc_vendor` (`entry`, `item`, `slot`, `maxcount`, `ExtendedCost`, `Type`, `VerifiedBuild`) VALUES
-- 49695
(49695, 2901, 1, 0, 0, 1, 20574), -- 2901
(49695, 5956, 2, 0, 0, 1, 20574), -- 5956
(49695, 2880, 3, 0, 0, 1, 20574), -- 2880
(49695, 3466, 4, 0, 0, 1, 20574), -- 3466
(49695, 18567, 5, 0, 0, 1, 20574), -- 18567
(49695, 3857, 6, 0, 0, 1, 20574), -- 3857
-- 49726
(49726, 2901, 1, 0, 0, 1, 20574), -- 2901
(49726, 5956, 2, 0, 0, 1, 20574), -- 5956
(49726, 2880, 3, 0, 0, 1, 20574), -- 2880
(49726, 3466, 4, 0, 0, 1, 20574), -- 3466
(49726, 18567, 5, 0, 0, 1, 20574), -- 18567
(49726, 3857, 6, 0, 0, 1, 20574), -- 3857
-- 49729
(49729, 2723, 1, 0, 0, 1, 20574), -- 2723
(49729, 2593, 2, 0, 0, 1, 20574), -- 2593
(49729, 2596, 3, 0, 0, 1, 20574), -- 2596
(49729, 2594, 4, 0, 0, 1, 20574), -- 2594
(49729, 2595, 5, 0, 0, 1, 20574), -- 2595
(49729, 83095, 6, 0, 0, 1, 20574), -- 83095
(49729, 82343, 7, 0, 0, 1, 20574), -- 82343
(49729, 83094, 8, 0, 0, 1, 20574), -- 83094
(49729, 82344, 9, 0, 0, 1, 20574), -- 82344
(49729, 2511, 10, 0, 0, 1, 20574), -- 2511
(49729, 3023, 11, 0, 0, 1, 20574), -- 3023
(49729, 3024, 12, 0, 0, 1, 20574), -- 3024
(49729, 3025, 13, 0, 0, 1, 20574), -- 3025
-- 50381
(50381, 52980, 1, 0, 3330, 1, 20574), -- 52980
(50381, 67080, 2, 0, 3330, 1, 20574), -- 67080
(50381, 67065, 3, 0, 3330, 1, 20574), -- 67065
(50381, 67054, 4, 0, 3330, 1, 20574), -- 67054
(50381, 67093, 5, 0, 3330, 1, 20574), -- 67093
(50381, 67066, 6, 0, 3330, 1, 20574), -- 67066
(50381, 67081, 7, 0, 3330, 1, 20574), -- 67081
(50381, 67092, 8, 0, 3330, 1, 20574), -- 67092
(50381, 67055, 9, 0, 3330, 1, 20574), -- 67055
(50381, 67076, 10, 0, 3330, 1, 20574), -- 67076
(50381, 67060, 11, 0, 3330, 1, 20574), -- 67060
(50381, 67046, 12, 0, 3330, 1, 20574), -- 67046
(50381, 67087, 13, 0, 3330, 1, 20574), -- 67087
(50381, 67048, 14, 0, 3330, 1, 20574), -- 67048
(50381, 67077, 15, 0, 3330, 1, 20574), -- 67077
(50381, 67089, 16, 0, 3330, 1, 20574), -- 67089
(50381, 67062, 17, 0, 3330, 1, 20574), -- 67062
(50381, 67064, 18, 0, 3330, 1, 20574), -- 67064
(50381, 67063, 19, 0, 3330, 1, 20574), -- 67063
(50381, 67049, 20, 0, 3330, 1, 20574), -- 67049
(50381, 67090, 21, 0, 3330, 1, 20574), -- 67090
(50381, 67053, 22, 0, 3330, 1, 20574), -- 67053
(50381, 67091, 23, 0, 3330, 1, 20574), -- 67091
(50381, 67079, 24, 0, 3330, 1, 20574), -- 67079
(50381, 67078, 25, 0, 3330, 1, 20574), -- 67078
(50381, 67044, 26, 0, 3330, 1, 20574), -- 67044
(50381, 67058, 27, 0, 3330, 1, 20574), -- 67058
(50381, 67042, 28, 0, 3330, 1, 20574), -- 67042
(50381, 67075, 29, 0, 3330, 1, 20574), -- 67075
(50381, 67056, 30, 0, 3330, 1, 20574), -- 67056
(50381, 67086, 31, 0, 3330, 1, 20574), -- 67086
(50381, 67085, 32, 0, 3330, 1, 20574), -- 67085
(50381, 67074, 33, 0, 3330, 1, 20574), -- 67074
(50381, 67095, 34, 0, 3330, 1, 20574), -- 67095
(50381, 67070, 35, 0, 3330, 1, 20574), -- 67070
(50381, 67084, 36, 0, 3330, 1, 20574), -- 67084
(50381, 67094, 37, 0, 3330, 1, 20574), -- 67094
(50381, 67073, 38, 0, 3330, 1, 20574), -- 67073
(50381, 67100, 39, 0, 3330, 1, 20574), -- 67100
(50381, 68193, 40, 0, 3330, 1, 20574), -- 68193
(50381, 71721, 41, 0, 3330, 1, 20574), -- 71721
(50381, 67068, 42, 0, 3330, 1, 20574), -- 67068
(50381, 67082, 43, 0, 3330, 1, 20574), -- 67082
(50381, 67072, 44, 0, 3330, 1, 20574), -- 67072
(50381, 67083, 45, 0, 3330, 1, 20574), -- 67083
(50381, 67096, 46, 0, 3330, 1, 20574), -- 67096
-- 50382
(50382, 66117, 1, 0, 3312, 1, 20574), -- 66117
(50382, 66118, 2, 0, 3312, 1, 20574), -- 66118
(50382, 66125, 3, 0, 3312, 1, 20574), -- 66125
(50382, 66126, 4, 0, 3312, 1, 20574), -- 66126
(50382, 66103, 5, 0, 3312, 1, 20574), -- 66103
(50382, 66119, 6, 0, 3312, 1, 20574), -- 66119
(50382, 66107, 7, 0, 3312, 1, 20574), -- 66107
(50382, 66105, 8, 0, 3312, 1, 20574), -- 66105
(50382, 66109, 9, 0, 3312, 1, 20574), -- 66109
(50382, 66127, 10, 0, 3312, 1, 20574), -- 66127
(50382, 66120, 11, 0, 3313, 1, 20574), -- 66120
(50382, 67603, 12, 0, 3313, 1, 20574), -- 67603
(50382, 67606, 13, 0, 3314, 1, 20574), -- 67606
(50382, 66113, 14, 0, 3313, 1, 20574), -- 66113
(50382, 66106, 15, 0, 3313, 1, 20574), -- 66106
(50382, 66111, 16, 0, 3313, 1, 20574), -- 66111
(50382, 66104, 17, 0, 3313, 1, 20574), -- 66104
(50382, 66108, 18, 0, 3313, 1, 20574), -- 66108
(50382, 66128, 19, 0, 3313, 1, 20574), -- 66128
(50382, 66121, 20, 0, 3313, 1, 20574), -- 66121
(50382, 66115, 21, 0, 3313, 1, 20574), -- 66115
(50382, 66112, 22, 0, 3313, 1, 20574), -- 66112
(50382, 66114, 23, 0, 3313, 1, 20574), -- 66114
(50382, 66110, 24, 0, 3313, 1, 20574), -- 66110
(50382, 66116, 25, 0, 3313, 1, 20574), -- 66116
(50382, 66129, 26, 0, 3313, 1, 20574), -- 66129
(50382, 66124, 27, 0, 3314, 1, 20574), -- 66124
(50382, 66123, 28, 0, 3314, 1, 20574), -- 66123
(50382, 66122, 29, 0, 3314, 1, 20574), -- 66122
(50382, 66100, 30, 0, 3314, 1, 20574), -- 66100
(50382, 66132, 31, 0, 3314, 1, 20574), -- 66132
(50382, 66131, 32, 0, 3314, 1, 20574), -- 66131
(50382, 66130, 33, 0, 3314, 1, 20574), -- 66130
(50382, 66101, 34, 0, 3314, 1, 20574), -- 66101
-- 50134
(50134, 67312, 1, 0, 3326, 1, 20574), -- 67312
(50134, 64411, 3, 0, 3016, 1, 20574), -- 64411
(50134, 64412, 4, 0, 3016, 1, 20574), -- 64412
(50134, 52738, 5, 0, 3016, 1, 20574), -- 52738
(50134, 64413, 6, 0, 3016, 1, 20574), -- 64413
(50134, 52740, 7, 0, 3016, 1, 20574), -- 52740
(50134, 52739, 8, 0, 3016, 1, 20574), -- 52739
(50134, 52737, 9, 0, 3016, 1, 20574), -- 52737
(50134, 64414, 10, 0, 3016, 1, 20574), -- 64414
(50134, 64415, 11, 0, 3016, 1, 20574), -- 64415
(50134, 52736, 12, 0, 3017, 1, 20574), -- 52736
(50134, 52733, 13, 0, 3017, 1, 20574), -- 52733
(50134, 52735, 14, 0, 3017, 1, 20574), -- 52735
-- 49733
(49733, 64670, 1, 0, 0, 1, 20574), -- 64670
(49733, 63388, 2, 0, 0, 1, 20574), -- 63388
(49733, 79249, 3, 0, 0, 1, 20574), -- 79249
-- 49702
(49702, 59496, 1, 0, 3306, 1, 20574), -- 59496
(49702, 59493, 2, 0, 3307, 1, 20574), -- 59493
(49702, 59491, 3, 0, 3305, 1, 20574), -- 59491
(49702, 59480, 4, 0, 3308, 1, 20574), -- 59480
(49702, 59479, 5, 0, 3311, 1, 20574), -- 59479
(49702, 59478, 6, 0, 3311, 1, 20574), -- 59478
(49702, 59477, 7, 0, 3392, 1, 20574), -- 59477
(49702, 59489, 8, 0, 3310, 1, 20574), -- 59489
(49702, 68660, 9, 0, 989, 1, 20574), -- 68660
(49702, 5956, 10, 0, 0, 1, 20574), -- 5956
(49702, 2901, 11, 0, 0, 1, 20574), -- 2901
(49702, 90146, 12, 0, 0, 1, 20574), -- 90146
(49702, 4399, 13, 0, 0, 1, 20574), -- 4399
(49702, 4400, 14, 0, 0, 1, 20574), -- 4400
(49702, 40533, 15, 0, 0, 1, 20574), -- 40533
(49702, 39684, 16, 0, 0, 1, 20574), -- 39684
(49702, 2880, 17, 0, 0, 1, 20574), -- 2880
(49702, 3466, 18, 0, 0, 1, 20574), -- 3466
(49702, 39354, 19, 0, 0, 1, 20574), -- 39354
(49702, 10647, 20, 0, 0, 1, 20574), -- 10647
(49702, 4470, 21, 0, 0, 1, 20574), -- 4470
(49702, 30746, 22, 0, 0, 1, 20574), -- 30746
(49702, 3857, 23, 0, 0, 1, 20574), -- 3857
(49702, 20815, 24, 0, 0, 1, 20574), -- 20815
-- 49703
(49703, 3371, 1, 0, 0, 1, 20574), -- 3371
(49703, 39505, 2, 0, 0, 1, 20574), -- 39505
(49703, 39489, 3, 0, 0, 1, 20574), -- 39489
(49703, 39354, 4, 0, 0, 1, 20574), -- 39354
(49703, 64670, 5, 0, 0, 1, 20574), -- 64670
(49703, 63388, 6, 0, 0, 1, 20574), -- 63388
(49703, 62323, 7, 0, 0, 1, 20574), -- 62323
(49703, 68047, 8, 0, 0, 1, 20574), -- 68047
(49703, 67348, 9, 0, 0, 1, 20574), -- 67348
(49703, 67319, 10, 0, 0, 1, 20574), -- 67319
(49703, 67335, 11, 0, 0, 1, 20574), -- 67335
-- 50386
(50386, 68199, 1, 0, 2988, 1, 20574), -- 68199
(50386, 54600, 2, 0, 2988, 1, 20574), -- 54600
(50386, 54599, 3, 0, 2988, 1, 20574), -- 54599
(50386, 54593, 4, 0, 2988, 1, 20574), -- 54593
(50386, 54594, 5, 0, 2988, 1, 20574), -- 54594
(50386, 54595, 6, 0, 2988, 1, 20574), -- 54595
(50386, 54596, 7, 0, 2988, 1, 20574), -- 54596
(50386, 54597, 8, 0, 2988, 1, 20574), -- 54597
(50386, 54598, 9, 0, 2988, 1, 20574), -- 54598
(50386, 54604, 10, 0, 2989, 1, 20574), -- 54604
(50386, 54601, 11, 0, 2989, 1, 20574), -- 54601
(50386, 54603, 12, 0, 2989, 1, 20574), -- 54603
(50386, 54602, 13, 0, 2989, 1, 20574), -- 54602
(50386, 54605, 14, 0, 2989, 1, 20574), -- 54605
-- 49704
(49704, 58280, 1, 0, 0, 1, 20574), -- 58280
(49704, 58268, 2, 0, 0, 1, 20574), -- 58268
(49704, 58269, 3, 0, 0, 1, 20574), -- 58269
(49704, 58277, 4, 0, 0, 1, 20574), -- 58277
(49704, 58262, 5, 0, 0, 1, 20574), -- 58262
(49704, 58263, 6, 0, 0, 1, 20574), -- 58263
(49704, 58274, 7, 0, 0, 1, 20574), -- 58274
(49704, 58256, 8, 0, 0, 1, 20574), -- 58256
(49704, 58257, 9, 0, 0, 1, 20574), -- 58257
-- 49705
(49705, 2320, 1, 0, 0, 1, 20574), -- 2320
(49705, 2321, 2, 0, 0, 1, 20574), -- 2321
(49705, 4291, 3, 0, 0, 1, 20574), -- 4291
(49705, 8343, 4, 0, 0, 1, 20574), -- 8343
(49705, 14341, 5, 0, 0, 1, 20574), -- 14341
(49705, 38426, 6, 0, 0, 1, 20574), -- 38426
(49705, 2324, 7, 0, 0, 1, 20574), -- 2324
(49705, 2604, 8, 0, 0, 1, 20574), -- 2604
(49705, 6260, 9, 0, 0, 1, 20574), -- 6260
(49705, 2605, 10, 0, 0, 1, 20574), -- 2605
(49705, 4341, 11, 0, 0, 1, 20574), -- 4341
(49705, 4340, 12, 0, 0, 1, 20574), -- 4340
(49705, 6261, 13, 0, 0, 1, 20574), -- 6261
(49705, 2325, 14, 0, 0, 1, 20574), -- 2325
(49705, 4342, 15, 0, 0, 1, 20574), -- 4342
(49705, 10290, 16, 0, 0, 1, 20574), -- 10290
-- 49707
(49707, 20815, 1, 0, 0, 1, 20574), -- 20815
(49707, 52188, 2, 0, 0, 1, 20574), -- 52188
-- 49714
(49714, 7005, 1, 0, 0, 1, 20574), -- 7005
(49714, 4289, 2, 0, 0, 1, 20574), -- 4289
(49714, 2320, 3, 0, 0, 1, 20574), -- 2320
(49714, 2321, 4, 0, 0, 1, 20574), -- 2321
(49714, 4291, 5, 0, 0, 1, 20574), -- 4291
(49714, 8343, 6, 0, 0, 1, 20574), -- 8343
(49714, 14341, 7, 0, 0, 1, 20574), -- 14341
(49714, 38426, 8, 0, 0, 1, 20574), -- 38426
(49714, 2325, 9, 0, 0, 1, 20574), -- 2325
(49714, 6260, 10, 0, 0, 1, 20574), -- 6260
(49714, 2604, 11, 0, 0, 1, 20574), -- 2604
(49714, 2605, 12, 0, 0, 1, 20574), -- 2605
(49714, 4340, 13, 0, 0, 1, 20574), -- 4340
(49714, 4341, 14, 0, 0, 1, 20574), -- 4341
(49714, 6261, 15, 0, 0, 1, 20574), -- 6261
(49714, 4342, 16, 0, 0, 1, 20574), -- 4342
(49714, 10290, 17, 0, 0, 1, 20574), -- 10290
-- 50458
(50458, 38682, 925, 0, 0, 1, 20574), -- 38682
(50458, 6217, 926, 0, 0, 1, 20574), -- 6217
(50458, 10940, 927, 3, 0, 1, 20574), -- 10940
(50458, 10938, 928, 2, 0, 1, 20574), -- 10938
(50458, 4470, 929, 0, 0, 1, 20574), -- 4470
(50458, 11291, 930, 0, 0, 1, 20574), -- 11291
-- 49723
(49723, 2528, 1, 0, 0, 1, 20574), -- 2528
(49723, 2529, 2, 0, 0, 1, 20574), -- 2529
(49723, 2530, 3, 0, 0, 1, 20574), -- 2530
(49723, 2531, 4, 0, 0, 1, 20574), -- 2531
(49723, 2532, 5, 0, 0, 1, 20574), -- 2532
(49723, 2533, 6, 0, 0, 1, 20574), -- 2533
(49723, 2534, 7, 0, 0, 1, 20574), -- 2534
(49723, 2535, 8, 0, 0, 1, 20574); -- 2535

-- Hollows End Gameobject Spawns for highbank
SET @OGUID   := 224905;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID AND @OGUID+85;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseId`,`PhaseGroup`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@OGUID+0,180405,0,4922,0,1,0,551,-4818.865,-6642.418,11.50401,1.06465,0,0,0.5075378,0.8616294,120,255,1), -- G_Pumpkin_01
(@OGUID+1,180405,0,4922,0,1,0,551,-4826.821,-6725.12,11.34984,2.792518,0,0,0.984807,0.1736523,120,255,1), -- G_Pumpkin_01
(@OGUID+2,180405,0,4922,0,1,0,551,-4853.293,-6658.901,13.00761,1.099556,0,0,0.5224981,0.8526405,120,255,1), -- G_Pumpkin_01
(@OGUID+3,180405,0,4922,0,1,0,551,-4886.12,-6703.981,11.42979,0.2792516,0,0,0.1391726,0.9902682,120,255,1), -- G_Pumpkin_01
(@OGUID+4,180405,0,4922,0,1,0,551,-4774.193,-6727.476,11.62903,2.82743,0,0,0.9876881,0.1564362,120,255,1), -- G_Pumpkin_01
(@OGUID+5,180405,0,4922,0,1,0,551,-4783.031,-6602.446,11.49245,1.151916,0,0,0.5446386,0.8386708,120,255,1), -- G_Pumpkin_01
(@OGUID+6,180405,0,4922,0,1,0,551,-4739.585,-6734.573,11.44644,5.899214,0,0,-0.1908083,0.9816273,120,255,1), -- G_Pumpkin_01
(@OGUID+7,180405,0,4922,0,1,0,551,-4737.679,-6676.837,11.76568,4.293513,0,0,-0.8386698,0.5446402,120,255,1), -- G_Pumpkin_01
(@OGUID+8,180406,0,4922,0,1,0,551,-4741,-6653.141,11.78506,5.881761,0,0,-0.1993675,0.9799248,120,255,1), -- G_Pumpkin_02
(@OGUID+9,180406,0,4922,0,1,0,551,-4800.472,-6619.033,11.41338,0.4363316,0,0,0.2164392,0.9762961,120,255,1), -- G_Pumpkin_02
(@OGUID+10,180406,0,4922,0,1,0,551,-4902.713,-6687.012,11.36803,5.742135,0,0,-0.2672377,0.9636307,120,255,1), -- G_Pumpkin_02
(@OGUID+11,180406,0,4922,0,1,0,551,-4843.309,-6707.708,11.48819,3.508117,0,0,-0.9832544,0.182238,120,255,1), -- G_Pumpkin_02
(@OGUID+12,180406,0,4922,0,1,0,551,-4808.863,-6727.207,11.76127,4.363324,0,0,-0.8191519,0.5735767,120,255,1), -- G_Pumpkin_02
(@OGUID+13,180406,0,4922,0,1,0,551,-4754.327,-6693.432,11.83969,4.258607,0,0,-0.8480473,0.5299206,120,255,1), -- G_Pumpkin_02
(@OGUID+14,180406,0,4922,0,1,0,551,-4758.259,-6744.484,11.56098,2.82743,0,0,0.9876881,0.1564362,120,255,1), -- G_Pumpkin_02
(@OGUID+15,180406,0,4922,0,1,0,551,-4868.327,-6687.99,11.49731,1.099556,0,0,0.5224981,0.8526405,120,255,1), -- G_Pumpkin_02
(@OGUID+16,180407,0,4922,0,1,0,551,-4817.307,-6601.594,11.31448,5.846854,0,0,-0.2164392,0.9762961,120,255,1), -- G_Pumpkin_03
(@OGUID+17,180407,0,4922,0,1,0,551,-4758.224,-6635.91,11.71685,5.009095,0,0,-0.5948229,0.8038568,120,255,1), -- G_Pumpkin_03
(@OGUID+18,180407,0,4922,0,1,0,551,-4755.384,-6717.057,11.36858,5.794494,0,0,-0.2419214,0.9702958,120,255,1), -- G_Pumpkin_03
(@OGUID+19,180407,0,4922,0,1,0,551,-4864.708,-6668.807,13.00744,1.204277,0,0,0.5664063,0.8241262,120,255,1), -- G_Pumpkin_03
(@OGUID+20,180407,0,4922,0,1,0,551,-4859.927,-6724.766,11.57767,4.293513,0,0,-0.8386698,0.5446402,120,255,1), -- G_Pumpkin_03
(@OGUID+21,180407,0,4922,0,1,0,551,-4791.252,-6711.05,11.68616,3.612838,0,0,-0.9723692,0.2334484,120,255,1), -- G_Pumpkin_03
(@OGUID+22,180407,0,4922,0,1,0,551,-4834.689,-6657.984,11.4773,1.204277,0,0,0.5664063,0.8241262,120,255,1), -- G_Pumpkin_03
(@OGUID+23,180410,0,4922,0,1,0,551,-4709.721,-6680.208,10.96661,3.001947,0,0,0.9975634,0.06976615,120,255,1), -- G_HangingSkeleton_01
(@OGUID+24,180411,0,4922,0,1,0,551,-4863.625,-6654.557,14.87818,1.884953,0,0,0.8090162,0.5877863,120,255,1), -- G_Ghost_01
(@OGUID+25,180415,0,4922,0,1,0,551,-4795.075,-6597.278,10.76079,0,0,0,0,1,120,255,1), -- CandleBlack01
(@OGUID+26,180415,0,4922,0,1,0,551,-4796.274,-6597.269,9.416761,0,0,0,0,1,120,255,1), -- CandleBlack01
(@OGUID+27,180415,0,4922,0,1,0,551,-4855.662,-6654.153,9.046175,0,0,0,0,1,120,255,1), -- CandleBlack01
(@OGUID+28,180415,0,4922,0,1,0,551,-4854.684,-6651.925,9.280835,0,0,0,0,1,120,255,1), -- CandleBlack01
(@OGUID+29,180415,0,4922,0,1,0,551,-4853.986,-6650.042,9.401288,0,0,0,0,1,120,255,1), -- CandleBlack01
(@OGUID+30,180426,0,4922,0,1,0,551,-4776.601,-6686.569,15.90509,0,0,0,0,1,120,255,1), -- Bat01
(@OGUID+31,180426,0,4922,0,1,0,551,-4797.17,-6642.559,15.90647,0,0,0,0,1,120,255,1), -- Bat01
(@OGUID+32,180426,0,4922,0,1,0,551,-4850.932,-6686.221,5.497849,0,0,0,0,1,120,255,1), -- Bat01
(@OGUID+33,180426,0,4922,0,1,0,551,-4764.172,-6657.143,15.93045,0,0,0,0,1,120,255,1), -- Bat01
(@OGUID+34,180426,0,4922,0,1,0,551,-4821.318,-6674.846,4.333151,0,0,0,0,1,120,255,1), -- Bat01
(@OGUID+35,180427,0,4922,0,1,0,551,-4789.46,-6643.111,15.94717,0,0,0,0,1,120,255,1), -- Bat02
(@OGUID+36,180427,0,4922,0,1,0,551,-4787.569,-6677.958,19.4448,0,0,0,0,1,120,255,1), -- Bat02
(@OGUID+37,180427,0,4922,0,1,0,551,-4836.535,-6681.958,4.6734,0,0,0,0,1,120,255,1), -- Bat02
(@OGUID+38,180427,0,4922,0,1,0,551,-4802.266,-6680.385,17.86889,0,0,0,0,1,120,255,1), -- Bat02
(@OGUID+39,180427,0,4922,0,1,0,551,-4810.03,-6700.222,27.38307,0,0,0,0,1,120,255,1), -- Bat02
(@OGUID+40,180429,0,4922,0,1,0,551,-4846.097,-6646.038,11.34216,0.6283169,0,0,0.3090162,0.9510568,120,255,1), -- G_WitchHat_01 scale 0.5
(@OGUID+41,180429,0,4922,0,1,0,551,-4836.526,-6637.009,11.30549,0.6283169,0,0,0.3090162,0.9510568,120,255,1), -- G_WitchHat_01 scale 0.5
(@OGUID+42,180471,0,4922,0,1,0,551,-4837.495,-6616.484,12.77096,1.169369,0,0,0.5519361,0.8338864,120,255,1), -- HangingSkullLight01
(@OGUID+43,180471,0,4922,0,1,0,551,-4819.087,-6585.917,12.19769,5.93412,0,0,-0.1736479,0.9848078,120,255,1), -- HangingSkullLight01
(@OGUID+44,180471,0,4922,0,1,0,551,-4839.776,-6588.337,12.32707,2.530723,0,0,0.9537163,0.3007079,120,255,1), -- HangingSkullLight01
(@OGUID+45,180471,0,4922,0,1,0,551,-4842.764,-6595.385,12.31158,5.829401,0,0,-0.2249508,0.9743701,120,255,1), -- HangingSkullLight01
(@OGUID+46,180471,0,4922,0,1,0,551,-4833.478,-6591.33,12.32832,3.194002,0,0,-0.9996567,0.02620165,120,255,1), -- HangingSkullLight01
(@OGUID+47,180471,0,4922,0,1,0,551,-4848.26,-6614.863,12.77606,3.909541,0,0,-0.9271832,0.3746083,120,255,1), -- HangingSkullLight01
(@OGUID+48,180471,0,4922,0,1,0,551,-4842.307,-6610.17,12.7793,2.146753,0,0,0.8788166,0.4771597,120,255,1), -- HangingSkullLight01
(@OGUID+49,180471,0,4922,0,1,0,551,-4840.292,-6588.681,12.33683,4.32842,0,0,-0.8290367,0.5591941,120,255,1), -- HangingSkullLight01
(@OGUID+50,180471,0,4922,0,1,0,551,-4845.415,-6577,11.92549,5.916668,0,0,-0.1822348,0.983255,120,255,1), -- HangingSkullLight01
(@OGUID+51,180471,0,4922,0,1,0,551,-4833.338,-6591.87,12.25795,0.9250238,0,0,0.4461975,0.8949345,120,255,1), -- HangingSkullLight01
(@OGUID+52,180471,0,4922,0,1,0,551,-4860.295,-6580.653,12.08788,1.029743,0,0,0.4924231,0.870356,120,255,1), -- HangingSkullLight01
(@OGUID+53,180471,0,4922,0,1,0,551,-4836.203,-6597.941,12.25213,1.169369,0,0,0.5519361,0.8338864,120,255,1), -- HangingSkullLight01
(@OGUID+54,180471,0,4922,0,1,0,551,-4842.891,-6621.212,12.76513,0.8726639,0,0,0.4226179,0.9063079,120,255,1), -- HangingSkullLight01
(@OGUID+55,180471,0,4922,0,1,0,551,-4843.84,-6621.099,12.78331,5.218536,0,0,-0.5075378,0.8616294,120,255,1), -- HangingSkullLight01
(@OGUID+56,180471,0,4922,0,1,0,551,-4832.587,-6581.05,12.24675,5.689774,0,0,-0.2923717,0.9563047,120,255,1), -- HangingSkullLight01
(@OGUID+57,180471,0,4922,0,1,0,551,-4836.948,-6598.165,12.28483,5.846854,0,0,-0.2164392,0.9762961,120,255,1), -- HangingSkullLight01
(@OGUID+58,180471,0,4922,0,1,0,551,-4855.502,-6576.037,12.08103,0.5759573,0,0,0.2840147,0.9588199,120,255,1), -- HangingSkullLight01
(@OGUID+59,180471,0,4922,0,1,0,551,-4863.425,-6590.106,12.72501,1.570796,0,0,0.7071066,0.7071069,120,255,1), -- HangingSkullLight01
(@OGUID+60,180471,0,4922,0,1,0,551,-4843.018,-6610.252,12.78796,3.874631,0,0,-0.9335804,0.358368,120,255,1), -- HangingSkullLight01
(@OGUID+61,180471,0,4922,0,1,0,551,-4843.054,-6594.554,12.32471,4.34587,0,0,-0.8241262,0.5664061,120,255,1), -- HangingSkullLight01
(@OGUID+62,180471,0,4922,0,1,0,551,-4851.418,-6574.972,11.93286,6.265733,0,0,-0.00872612,0.9999619,120,255,1), -- HangingSkullLight01
(@OGUID+63,180471,0,4922,0,1,0,551,-4825.656,-6583.632,12.19699,6.021387,0,0,-0.1305256,0.9914449,120,255,1), -- HangingSkullLight01
(@OGUID+64,180471,0,4922,0,1,0,551,-4861.512,-6582.952,12.7211,1.012289,0,0,0.4848089,0.8746201,120,255,1), -- HangingSkullLight01
(@OGUID+65,180471,0,4922,0,1,0,551,-4837.347,-6615.854,12.77853,1.989672,0,0,0.8386698,0.5446402,120,255,1), -- HangingSkullLight01
(@OGUID+66,180471,0,4922,0,1,0,551,-4848.465,-6615.806,12.80338,5.183629,0,0,-0.5224981,0.8526405,120,255,1), -- HangingSkullLight01
(@OGUID+67,180471,0,4922,0,1,0,551,-4839.111,-6578.877,12.24825,5.881761,0,0,-0.1993675,0.9799248,120,255,1), -- HangingSkullLight01
(@OGUID+68,180471,0,4922,0,1,0,551,-4864.162,-6653.74,17.07137,0.9250238,0,0,0.4461975,0.8949345,120,255,1), -- HangingSkullLight01
(@OGUID+69,180471,0,4922,0,1,0,551,-4865.219,-6654.559,17.19308,0.7679439,0,0,0.3746061,0.927184,120,255,1), -- HangingSkullLight01
(@OGUID+70,180471,0,4922,0,1,0,551,-4866.141,-6655.253,17.29807,0.7155849,0,0,0.3502073,0.9366722,120,255,1), -- HangingSkullLight01
(@OGUID+71,180471,0,4922,0,1,0,551,-4867.236,-6656.21,17.17282,0.7155849,0,0,0.3502073,0.9366722,120,255,1), -- HangingSkullLight01
(@OGUID+72,180471,0,4922,0,1,0,551,-4868.115,-6657.03,17.06358,0.7155849,0,0,0.3502073,0.9366722,120,255,1), -- HangingSkullLight01
(@OGUID+73,180472,0,4922,0,1,0,551,-4716.953,-6658.549,13.20601,3.351047,0,0,-0.9945211,0.1045355,120,255,1), -- HangingSkullLight02
(@OGUID+74,180472,0,4922,0,1,0,551,-4739.118,-6749.149,13.54163,2.216565,0,0,0.8949337,0.4461992,120,255,1), -- HangingSkullLight02
(@OGUID+75,180472,0,4922,0,1,0,551,-4743.618,-6753.552,13.57957,2.460913,0,0,0.9426413,0.3338076,120,255,1), -- HangingSkullLight02
(@OGUID+76,180472,0,4922,0,1,0,551,-4714.533,-6664.198,13.33271,3.490667,0,0,-0.984807,0.1736523,120,255,1), -- HangingSkullLight02
(@OGUID+77,180523,0,4922,0,1,0,551,-4881.092,-6596.736,11.2802,5.061456,0,0,-0.573576,0.8191524,120,255,1), -- Apple Bob
(@OGUID+78,180523,0,4922,0,1,0,551,-4922.931,-6621.186,11.19169,5.061456,0,0,-0.573576,0.8191524,120,255,1), -- Apple Bob
(@OGUID+79,185434,0,4922,0,1,0,551,-4857.63,-6651.753,9.177757,0.2792516,0,0,0.1391726,0.9902682,120,255,1), -- Sitting Skeleton 01
(@OGUID+80,185436,0,4922,0,1,0,551,-4857.467,-6649.728,9.414888,5.078908,0,0,-0.5664063,0.8241262,120,255,1), -- Sitting Skeleton 03
(@OGUID+81,185438,0,4922,0,1,0,551,-4795.783,-6597.528,9.416761,3.787367,0,0,-0.9483232,0.3173059,120,255,1), -- Sitting Skeleton 04
(@OGUID+82,185454,0,4922,0,1,0,551,-4855.448,-6649.353,9.408929,0.9599299,0,0,0.4617481,0.8870111,120,255,1), -- Laying Skeleton 02
(@OGUID+83,208077,0,4922,0,1,0,551,-4855.762,-6649.231,10.15548,2.775069,0,0,0.9832544,0.182238,120,255,1), -- 
(@OGUID+84,208129,0,4922,0,1,0,551,-4890.484,-6594.458,10.83288,0.9424766,0,0,0.45399,0.8910068,120,255,1), -- Candy Bucket
(@OGUID+85,208129,0,4922,0,1,0,551,-4916.667,-6626.691,10.83049,5.445428,0,0,-0.4067364,0.9135455,120,255,1); -- Candy Bucket

DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN @OGUID AND @OGUID+85;
INSERT INTO `game_event_gameobject` (`eventEntry`,`guid`) VALUES
(12,@OGUID+0),
(12,@OGUID+1),
(12,@OGUID+2),
(12,@OGUID+3),
(12,@OGUID+4),
(12,@OGUID+5),
(12,@OGUID+6),
(12,@OGUID+7),
(12,@OGUID+8),
(12,@OGUID+9),
(12,@OGUID+10),
(12,@OGUID+11),
(12,@OGUID+12),
(12,@OGUID+13),
(12,@OGUID+14),
(12,@OGUID+15),
(12,@OGUID+16),
(12,@OGUID+17),
(12,@OGUID+18),
(12,@OGUID+19),
(12,@OGUID+20),
(12,@OGUID+21),
(12,@OGUID+22),
(12,@OGUID+23),
(12,@OGUID+24),
(12,@OGUID+25),
(12,@OGUID+26),
(12,@OGUID+27),
(12,@OGUID+28),
(12,@OGUID+29),
(12,@OGUID+30),
(12,@OGUID+31),
(12,@OGUID+32),
(12,@OGUID+33),
(12,@OGUID+34),
(12,@OGUID+35),
(12,@OGUID+36),
(12,@OGUID+37),
(12,@OGUID+38),
(12,@OGUID+39),
(12,@OGUID+40),
(12,@OGUID+41),
(12,@OGUID+42),
(12,@OGUID+43),
(12,@OGUID+44),
(12,@OGUID+45),
(12,@OGUID+46),
(12,@OGUID+47),
(12,@OGUID+48),
(12,@OGUID+49),
(12,@OGUID+50),
(12,@OGUID+51),
(12,@OGUID+52),
(12,@OGUID+53),
(12,@OGUID+54),
(12,@OGUID+55),
(12,@OGUID+56),
(12,@OGUID+57),
(12,@OGUID+58),
(12,@OGUID+59),
(12,@OGUID+60),
(12,@OGUID+61),
(12,@OGUID+62),
(12,@OGUID+63),
(12,@OGUID+64),
(12,@OGUID+65),
(12,@OGUID+66),
(12,@OGUID+67),
(12,@OGUID+68),
(12,@OGUID+69),
(12,@OGUID+70),
(12,@OGUID+71),
(12,@OGUID+72),
(12,@OGUID+73),
(12,@OGUID+74),
(12,@OGUID+75),
(12,@OGUID+76),
(12,@OGUID+77),
(12,@OGUID+78),
(12,@OGUID+79),
(12,@OGUID+80),
(12,@OGUID+81),
(12,@OGUID+82),
(12,@OGUID+83),
(12,@OGUID+84),
(12,@OGUID+85);

-- Twilight Highlands Area: 5140 Highbank Phase 361
-- Spawn as group is added so hopefully in the future correct spawning will be available and these can be corrected
SET @CGUID := 250399;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+487;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
-- Spawn as group
(@CGUID+0, 49023, 0, 1, 361, 0, -4813.571, -6612.257, 5.885417, 4.415683, 120, 0, 0), -- Highbank Guardsman
(@CGUID+1, 49008, 0, 1, 361, 0, -4814.033, -6614.156, 6.125, 1.466077, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+2, 49023, 0, 1, 361, 0, -4826.946, -6615.625, 8.583333, 5.044002, 120, 0, 0), -- Highbank Guardsman
(@CGUID+3, 49008, 0, 1, 361, 0, -4826.141, -6617.41, 8.475695, 2.094395, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+4, 49028, 0, 1, 361, 0, -4937.382, -6727.776, 5.684081, 4.607669, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+5, 49008, 0, 1, 361, 0, -4937.167, -6729.734, 5.622865, 1.658063, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+6, 49028, 0, 1, 361, 0, -4922.116, -6733.978, 5.480845, 4.049164, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+7, 49008, 0, 1, 361, 0, -4924.040, -6734.359, 5.486672, 0.03490658, 120, 0, 0), -- Axebite Infantry
(@CGUID+8, 49008, 0, 1, 361, 0, -4923.071, -6735.698, 5.503015, 1.099557, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+9, 49028, 0, 1, 361, 0, -4920.597, -6749.287, 5.857955, 2.844887, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+10, 49008, 0, 1, 361, 0, -4922.537, -6748.993, 5.773934, 6.178465, 120, 0, 0), -- Axebite Infantry
(@CGUID+11, 49008, 0, 1, 361, 0, -4921.625, -6747.609, 5.794590, 5.113815, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+12, 49028, 0, 1, 361, 0, -4911.184, -6763.455, 15.34808, 2.617994, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+13, 49008, 0, 1, 361, 0, -4913.026, -6762.778, 15.34808, 5.951573, 120, 0, 0), -- Axebite Infantry
(@CGUID+14, 49008, 0, 1, 361, 0, -4911.851, -6761.606, 15.34806, 4.886922, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+15, 49028, 0, 1, 361, 0, -4905.859, -6755.088, 15.34792, 2.338741, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+16, 49008, 0, 1, 361, 0, -4907.463, -6753.957, 15.34790, 5.672320, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+17, 49028, 0, 1, 361, 0, -4903.564, -6730.807, 0.716454, 2.687807, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+18, 49008, 0, 1, 361, 0, -4905.481, -6730.363, 0.716454, 6.021386, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+19, 49023, 0, 1, 361, 0, -4885.599, -6722.557, 4.609375, 3.508112, 120, 0, 0), -- Highbank Guardsman
(@CGUID+20, 49008, 0, 1, 361, 0, -4887.333, -6721.649, 4.657986, 5.77704, 120, 0, 0), -- Axebite Infantry
(@CGUID+21, 49008, 0, 1, 361, 0, -4887.408, -6723.290, 4.625000, 0.5585054, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+22, 49023, 0, 1, 361, 0, -4899.943, -6706.448, 4.960070, 4.817109, 120, 0, 0), -- Highbank Guardsman
(@CGUID+23, 49008, 0, 1, 361, 0, -4899.696, -6708.389, 4.883558, 1.867502, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+24, 49023, 0, 1, 361, 0, -4871.057, -6702.424, 5.056917, 3.525565, 120, 0, 0), -- Highbank Guardsman
(@CGUID+25, 49023, 0, 1, 361, 0, -4872.859, -6701.649, 5.147570, 4.747295, 120, 0, 0), -- Highbank Guardsman
(@CGUID+26, 49008, 0, 1, 361, 0, -4872.806, -6703.295, 5.041667, 0.6108652, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+27, 49023, 0, 1, 361, 0, -4858.778, -6705.347, 4.426899, 3.368485, 120, 0, 0), -- Highbank Guardsman
(@CGUID+28, 49023, 0, 1, 361, 0, -4863.813, -6707.742, 4.453932, 4.813225, 120, 0, 0), -- Highbank Guardsman
(@CGUID+29, 49023, 0, 1, 361, 0, -4864.139, -6704.717, 4.453932, 5.961940, 120, 0, 0), -- Highbank Guardsman
(@CGUID+30, 49008, 0, 1, 361, 0, -4860.660, -6705.875, 4.413740, 0.418879, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+31, 49023, 0, 1, 361, 0, -4875.885, -6684.418, 9.496346, 6.195919, 120, 0, 0), -- Highbank Guardsman
(@CGUID+32, 49008, 0, 1, 361, 0, -4873.938, -6684.519, 9.485417, 3.246312, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+33, 49023, 0, 1, 361, 0, -4854.385, -6681.247, 6.984375, 4.520403, 120, 0, 0), -- Highbank Guardsman
(@CGUID+34, 49023, 0, 1, 361, 0, -4856.078, -6682.233, 7.092014, 5.742133, 120, 0, 0), -- Highbank Guardsman
(@CGUID+35, 49008, 0, 1, 361, 0, -4854.726, -6683.170, 6.748264, 1.605703, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+36, 49023, 0, 1, 361, 0, -4826.073, -6708.563, 5.240479, 2.286381, 120, 0, 0), -- Highbank Guardsman
(@CGUID+37, 49008, 0, 1, 361, 0, -4827.427, -6707.158, 5.240479, 5.61996, 120, 0, 0), -- Axebite Infantry
(@CGUID+38, 49008, 0, 1, 361, 0, -4825.878, -6706.616, 5.240479, 4.555309, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+39, 49028, 0, 1, 361, 0, -4851.962, -6597.481, 9.500094, 0.3665192, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+40, 49008, 0, 1, 361, 0, -4850.104, -6598.109, 9.500094, 2.635447, 120, 0, 0), -- Axebite Infantry
(@CGUID+41, 49008, 0, 1, 361, 0, -4850.272, -6596.471, 9.500094, 3.700098, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+42, 49023, 0, 1, 361, 0, -4812.707, -6684.587, 5.171875, 3.508112, 120, 0, 0), -- Highbank Guardsman
(@CGUID+43, 49008, 0, 1, 361, 0, -4814.516, -6685.319, 5.026042, 0.5585054, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+44, 49023, 0, 1, 361, 0, -4822.783, -6682.608, 4.454861, 4.101524, 120, 0, 0), -- Highbank Guardsman
(@CGUID+45, 49008, 0, 1, 361, 0, -4823.908, -6684.205, 4.432292, 1.151917, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+46, 49023, 0, 1, 361, 0, -4791.080, -6700.528, 4.487267, 3.508112, 120, 0, 0), -- Highbank Guardsman
(@CGUID+47, 49008, 0, 1, 361, 0, -4792.889, -6701.260, 4.638889, 0.558505, 120, 0, 0), -- Axebite Infantry
(@CGUID+48, 49008, 0, 1, 361, 0, -4792.814, -6699.620, 4.412258, 5.777040, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+49, 49023, 0, 1, 361, 0, -4771.665, -6720.427, 4.623264, 2.129302, 120, 0, 0), -- Highbank Guardsman
(@CGUID+50, 49008, 0, 1, 361, 0, -4772.721, -6718.788, 4.422417, 5.462881, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+51, 49023, 0, 1, 361, 0, -4758.731, -6726.656, 5.230903, 2.827433, 120, 0, 0), -- Highbank Guardsman
(@CGUID+52, 49008, 0, 1, 361, 0, -4760.618, -6726.146, 5.169560, 6.161012, 120, 0, 0), -- Axebite Infantry
(@CGUID+53, 49008, 0, 1, 361, 0, -4759.564, -6724.887, 5.192611, 5.096361, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+54, 49023, 0, 1, 361, 0, -4758.266, -6749.479, 8.150346, 2.68698, 120, 0, 0), -- Highbank Guardsman
(@CGUID+55, 49008, 0, 1, 361, 0, -4761.458, -6747.918, 9.057543, 2.159376, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+56, 49023, 0, 1, 361, 0, -4753.708, -6704.978, 8.651041, 3.473205, 120, 0, 0), -- Highbank Guardsman
(@CGUID+57, 49023, 0, 1, 361, 0, -4754.019, -6706.910, 8.576388, 2.251475, 120, 0, 0), -- Highbank Guardsman
(@CGUID+58, 49008, 0, 1, 361, 0, -4755.292, -6705.424, 8.201388, 5.61996, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+59, 49023, 0, 1, 361, 0, -4762.564, -6673.448, 4.460159, 4.415683, 120, 0, 0), -- Highbank Guardsman
(@CGUID+60, 49023, 0, 1, 361, 0, -4761.863, -6678.821, 4.653106, 1.893769, 120, 0, 0), -- Highbank Guardsman
(@CGUID+61, 49008, 0, 1, 361, 0, -4763.026, -6675.347, 4.486111, 1.466077, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+62, 49023, 0, 1, 361, 0, -4813.375, -6648.599, 4.672303, 4.101524, 120, 0, 0), -- Highbank Guardsman
(@CGUID+63, 49008, 0, 1, 361, 0, -4814.500, -6650.196, 4.751736, 1.151917, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+64, 49023, 0, 1, 361, 0, -4808.144, -6645.753, 4.427713, 4.415683, 120, 0, 0), -- Highbank Guardsman
(@CGUID+65, 49008, 0, 1, 361, 0, -4808.606, -6647.653, 4.434028, 1.466077, 120, 0, 0), -- Axebite Infantry
-- Spawn as group
(@CGUID+66, 49028, 0, 1, 361, 0, -4836.557, -6610.594, 9.5, 5.166174, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+67, 49008, 0, 1, 361, 0, -4835.335, -6612.132, 9.425347, 2.216568, 120, 0, 0), -- Axebite Infantry
(@CGUID+68, 49023, 0, 1, 361, 0, -4831.678, -6612.150, 9.166187, 3.136653, 120, 0, 0), -- Highbank Guardsman
-- Spawn as group
(@CGUID+69, 49023, 0, 1, 361, 0, -4811.842, -6595.842, 9.500094, 2.775074, 120, 0, 0), -- Highbank Guardsman
(@CGUID+70, 49008, 0, 1, 361, 0, -4813.731, -6595.353, 9.500094, 6.108652, 120, 0, 0), -- Axebite Infantry
(@CGUID+71, 49028, 0, 1, 361, 0, -4817.118, -6593.948, 9.486526, 5.889992, 120, 0, 0), -- Tidebreaker Sailor
-- Spawn as group
(@CGUID+72, 49028, 0, 1, 361, 0, -4829.137, -6592.042, 9.500094, 4.607669, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+73, 49008, 0, 1, 361, 0, -4828.922, -6594.000, 9.500094, 1.658063, 120, 0, 0), -- Axebite Infantry
-- These are not grouped spawns
(@CGUID+74, 15631, 0, 1, 361, 0, -4885.189, -6628.674, 1.690827, 0, 120, 0, 0), -- Spotlight
(@CGUID+75, 49003, 0, 1, 361, 0, -5006.189, -6767.417, 44.4698, 0.1570796, 120, 0, 0), -- Newt <Gob Squad>
(@CGUID+76, 49004, 0, 1, 361, 0, -4985.424, -6762.045, 44.70174, 0.6981317, 120, 0, 0), -- Volt <Gob Squad>
(@CGUID+77, 49005, 0, 1, 361, 0, -4967.21, -6766.526, 6.998905, 0.5061455, 120, 0, 0), -- Grit <Gob Squad>
(@CGUID+78, 49006, 765, 1, 361, 0, -1.159882, -4.393965, -17.92173, 3.320813, 120, 0, 2), -- Skyshredder Crewmember
(@CGUID+79, 49006, 765, 1, 361, 0, 4.30127, -6.897217, -23.6703, 0.2599998, 120, 5, 1), -- Skyshredder Crewmember
(@CGUID+80, 49008, 0, 1, 361, 0, -4831.635, -6728.139, 10.59844, 4.68684, 120, 0, 0), -- Axebite Infantry
(@CGUID+81, 49008, 0, 1, 361, 0, -4950.207, -6764.040, 5.439907, 0.6806784, 120, 0, 0), -- Axebite Infantry
(@CGUID+82, 49008, 0, 1, 361, 0, -4951.358, -6761.622, 5.307824, 0.6457718, 120, 0, 0), -- Axebite Infantry
(@CGUID+83, 49009, 0, 1, 361, 0, -4959.969, -6753.724, 4.647132, 0.2617994, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+84, 49009, 0, 1, 361, 0, -4982.385, -6749.957, 5.866918, 6.248279, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+85, 49009, 0, 1, 361, 0, -4962.54, -6772.191, 7.092097, 1.204277, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+86, 49009, 0, 1, 361, 0, -4962.212, -6773.668, 9.24676, 1.029744, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+87, 49009, 0, 1, 361, 0, -4965.128, -6770.872, 7.743102, 0.8377581, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+88, 49009, 0, 1, 361, 0, -4969.052, -6773.236, 9.62704, 0.6632251, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+89, 49009, 0, 1, 361, 0, -4969.281, -6771.528, 9.174253, 0.8203048, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+90, 49018, 0, 1, 361, 0, -4895.228, -6624.559, 1.690827, 0.03490658, 120, 0, 0), -- Bilgewater Prisoner
(@CGUID+91, 49018, 0, 1, 361, 0, -4873.868, -6626.649, 1.690827, 3.193953, 120, 0, 0), -- Bilgewater Prisoner
(@CGUID+92, 49018, 0, 1, 361, 0, -4887.62, -6629.948, 1.690827, 0.8552113, 120, 0, 0), -- Bilgewater Prisoner
(@CGUID+93, 49018, 0, 1, 361, 0, -4895.099, -6630.859, 1.690827, 0.8377581, 120, 0, 0), -- Bilgewater Prisoner
(@CGUID+94, 49018, 0, 1, 361, 0, -4873.455, -6628.658, 1.690827, 2.740167, 120, 0, 0), -- Bilgewater Prisoner
(@CGUID+95, 49018, 0, 1, 361, 0, -4881.25, -6628.743, 1.690827, 2.268928, 120, 0, 0), -- Bilgewater Prisoner
(@CGUID+96, 49018, 0, 1, 361, 0, -4889.077, -6630.608, 1.690827, 0.8377581, 120, 0, 0), -- Bilgewater Prisoner
(@CGUID+97, 49018, 0, 1, 361, 0, -4895.397, -6626.25, 1.690827, 0.2268928, 120, 0, 0), -- Bilgewater Prisoner
(@CGUID+98, 49020, 0, 1, 361, 0, -4856.846, -6589.811, 10.67741, 5.497787, 120, 0, 0), -- Bilgewater Prisoner
(@CGUID+99, 49022, 0, 1, 361, 0, -4946.821, -6704.628, 15.12407, 5.340707, 120, 0, 0), -- Bilgewater Prisoner
(@CGUID+100, 49023, 0, 1, 361, 0, -4917.059, -6628.721, 10.91292, 5.393067, 120, 0, 0), -- Highbank Guardsman
(@CGUID+101, 49023, 0, 1, 361, 0, -4867.274, -6657.878, 10.93835, 5.497787, 120, 0, 0), -- Highbank Guardsman
(@CGUID+102, 49023, 0, 1, 361, 0, -4856.077, -6627.814, 10.91652, 2.268928, 120, 0, 0), -- Highbank Guardsman
(@CGUID+103, 49023, 0, 1, 361, 0, -4912.297, -6625.014, 19.04872, 3.944444, 120, 0, 0), -- Highbank Guardsman
(@CGUID+104, 49023, 0, 1, 361, 0, -4889.375, -6605.021, 19.04819, 0.7504916, 120, 0, 0), -- Highbank Guardsman
(@CGUID+105, 49023, 0, 1, 361, 0, -4867.778, -6616.653, 10.92625, 3.961897, 120, 0, 0), -- Highbank Guardsman
(@CGUID+106, 49023, 0, 1, 361, 0, -4894.266, -6661.287, 10.91652, 2.268928, 120, 0, 0), -- Highbank Guardsman
(@CGUID+107, 49023, 0, 1, 361, 0, -4904.272, -6647.181, 10.92572, 0.663225, 120, 0, 0), -- Highbank Guardsman
(@CGUID+108, 49023, 0, 1, 361, 0, -4882.702, -6601.434, 10.91288, 5.393067, 120, 0, 0), -- Highbank Guardsman
(@CGUID+109, 49023, 0, 1, 361, 0, -4789.387, -6677.272, 8.463285, 3.804818, 120, 0, 0), -- Highbank Guardsman
(@CGUID+110, 49023, 0, 1, 361, 0, -4723.460, -6661.226, 5.255830, 3.630285, 120, 0, 0), -- Highbank Guardsman
(@CGUID+111, 49023, 0, 1, 361, 0, -4766.582, -6640.444, 4.830093, 3.979351, 120, 0, 0), -- Highbank Guardsman
(@CGUID+112, 49023, 0, 1, 361, 0, -4798.503, -6626.021, 5.106183, 4.520403, 120, 0, 0), -- Highbank Guardsman
(@CGUID+113, 49023, 0, 1, 361, 0, -4744.231, -6743.851, 5.240479, 2.338741, 120, 0, 0), -- Highbank Guardsman
(@CGUID+114, 49023, 0, 1, 361, 0, -4818.776, -6735.615, 9.500101, 1.553343, 120, 0, 0), -- Highbank Guardsman
(@CGUID+115, 49023, 0, 1, 361, 0, -4914.340, -6675.747, 9.231830, 4.817109, 120, 0, 0), -- Highbank Guardsman
(@CGUID+116, 49024, 0, 1, 361, 0, -4835.597, -6641.047, 9.500101, 4.991642, 120, 0, 0), -- Highbank Marksman
(@CGUID+117, 49024, 0, 1, 361, 0, -4911.469, -6684.519, 7.123036, 5.412732, 120, 0, 0), -- Highbank Marksman
(@CGUID+118, 49024, 0, 1, 361, 0, -4835.953, -6716.276, 10.2448, 1.58825, 120, 0, 0), -- Highbank Marksman
(@CGUID+119, 49024, 0, 1, 361, 0, -4800.394, -6720.064, 10.58203, 2.583087, 120, 0, 0), -- Highbank Marksman
(@CGUID+120, 49024, 0, 1, 361, 0, -4835.424, -6748.915, 11.62405, 1.448623, 120, 0, 0), -- Highbank Marksman
(@CGUID+121, 49024, 0, 1, 361, 0, -4800.899, -6746.594, 12.71048, 2.251475, 120, 0, 0), -- Highbank Marksman
(@CGUID+122, 49024, 0, 1, 361, 0, -4761.162, -6741.213, 10.70583, 1.727876, 120, 0, 0), -- Highbank Marksman
(@CGUID+123, 49024, 0, 1, 361, 0, -4732.09, -6708.682, 13.75636, 3.560472, 120, 0, 0), -- Highbank Marksman
(@CGUID+124, 49024, 0, 1, 361, 0, -4749.566, -6644.613, 10.67724, 4.118977, 120, 0, 0), -- Highbank Marksman
(@CGUID+125, 49025, 0, 1, 361, 0, -4866.635, -6617.858, 31.99912, 0.7853982, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+126, 49025, 0, 1, 361, 0, -4872.503, -6611.552, 31.99956, 0.7679449, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+127, 49025, 0, 1, 361, 0, -4864.828, -6618.543, 31.99872, 0.8552113, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+128, 49025, 0, 1, 361, 0, -4867.478, -6611.191, 32.00049, 0.8901179, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+129, 49025, 0, 1, 361, 0, -4873.79, -6609.092, 31.99878, 0.6981317, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+130, 49025, 0, 1, 361, 0, -4903.616, -6601.679, 31.9981, 2.216568, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+131, 49025, 0, 1, 361, 0, -4858.003, -6617.712, 31.99781, 0.9773844, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+132, 49025, 0, 1, 361, 0, -4912.188, -6607.749, 31.99765, 2.216568, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+133, 49025, 0, 1, 361, 0, -4910.231, -6640.613, 31.9992, 3.333579, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+134, 49025, 0, 1, 361, 0, -4907.759, -6602.984, 31.99721, 2.146755, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+135, 49025, 0, 1, 361, 0, -4911.667, -6602.74, 31.99551, 2.338741, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+136, 49025, 0, 1, 361, 0, -4910.224, -6637.828, 31.99868, 3.403392, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+137, 49025, 0, 1, 361, 0, -4914.837, -6608.58, 31.99712, 2.146755, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+138, 49025, 0, 1, 361, 0, -4914.853, -6635.842, 31.99746, 3.525565, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+139, 49025, 0, 1, 361, 0, -4904.764, -6594.463, 31.99355, 2.338741, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+140, 49025, 0, 1, 361, 0, -4900.069, -6652.497, 31.99746, 3.769911, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+141, 49025, 0, 1, 361, 0, -4907.127, -6652.177, 31.99906, 3.892084, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+142, 49025, 0, 1, 361, 0, -4901.434, -6660.333, 31.99654, 3.700098, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+143, 49025, 0, 1, 361, 0, -4944.238, -6633.778, 14.16557, 2.687807, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+144, 49025, 0, 1, 361, 0, -4939.425, -6638.288, 15.34345, 3.159046, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+145, 49025, 0, 1, 361, 0, -4939.917, -6640.25, 15.43413, 2.932153, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+146, 49025, 0, 1, 361, 0, -4847.924, -6754.792, 11.5958, 3.577925, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+147, 49025, 0, 1, 361, 0, -4768.641, -6604.156, 4.486656, 0.9948376, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+148, 49025, 0, 1, 361, 0, -4774.853, -6607.962, 4.940972, 0.9424778, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+149, 49025, 0, 1, 361, 0, -4854.634, -6753.507, 13.68216, 3.909538, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+150, 49025, 0, 1, 361, 0, -4847.165, -6758.479, 11.57675, 3.089233, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+151, 49025, 0, 1, 361, 0, -4774.542, -6605.903, 4.814236, 0.9599311, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+152, 49025, 0, 1, 361, 0, -4738.096, -6630.443, 9.395833, 0.7679449, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+153, 49025, 0, 1, 361, 0, -4740.151, -6627.295, 9.24132, 0.2792527, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+154, 49025, 0, 1, 361, 0, -4731.375, -6629.167, 9.16493, 1.099557, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+155, 49025, 0, 1, 361, 0, -4703.851, -6659.609, 44.33189, 4.468043, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+156, 49025, 0, 1, 361, 0, -4701.634, -6665.71, 44.33188, 5.497787, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+157, 49025, 0, 1, 361, 0, -4702.04, -6660.238, 44.33189, 3.490659, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+158, 49025, 0, 1, 361, 0, -4694.552, -6655.37, 44.33189, 6.178465, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+159, 49025, 0, 1, 361, 0, -4691.443, -6660.064, 44.33187, 5.77704, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+160, 49025, 0, 1, 361, 0, -4692.118, -6658.599, 44.33187, 5.899213, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+161, 49025, 0, 1, 361, 0, -4736.234, -6762.545, 44.57782, 3.211406, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+162, 49025, 0, 1, 361, 0, -4740.151, -6766.853, 44.5778, 3.804818, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+163, 49025, 0, 1, 361, 0, -4736.035, -6766.79, 44.57781, 4.258604, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+164, 49025, 0, 1, 361, 0, -4730.297, -6771.202, 44.57781, 5.410521, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+165, 49025, 0, 1, 361, 0, -4726.319, -6768.158, 44.57781, 5.585053, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+166, 49025, 0, 1, 361, 0, -4729.766, -6769.233, 44.57782, 5.340707, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+167, 49028, 0, 1, 361, 0, -4945.202, -6711.776, 13.91588, 5.270895, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+168, 49028, 0, 1, 361, 0, -4942.080, -6707.866, 14.17494, 5.288348, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+169, 49029, 0, 1, 361, 0, -4884.967, -6627.035, 1.690827, 3.979351, 120, 0, 0), -- Highbank Prison Guard
(@CGUID+170, 49029, 0, 1, 361, 0, -4885.778, -6609.059, 1.69136, 3.857178, 120, 0, 0), -- Highbank Prison Guard
(@CGUID+171, 49029, 0, 1, 361, 0, -4904.372, -6632.09, 10.96582, 5.916666, 120, 0, 0), -- Highbank Prison Guard
(@CGUID+172, 49060, 0, 1, 361, 0, -4868.569, -6606.163, 31.9993, 0.8203048, 120, 0, 0), -- Highbank Cannon
(@CGUID+173, 49060, 0, 1, 361, 0, -4861.918, -6614.184, 31.99907, 0.9075712, 120, 0, 0), -- Highbank Cannon
(@CGUID+174, 49060, 0, 1, 361, 0, -4916.207, -6640.788, 31.99829, 3.455752, 120, 0, 0), -- Highbank Cannon
(@CGUID+175, 49060, 0, 1, 361, 0, -4916.804, -6602.932, 31.99275, 2.268928, 120, 0, 0), -- Highbank Cannon
(@CGUID+176, 49060, 0, 1, 361, 0, -4903.747, -6655.512, 31.99792, 3.822271, 120, 0, 0), -- Highbank Cannon
(@CGUID+177, 49060, 0, 1, 361, 0, -4908.233, -6596.863, 31.99321, 2.268928, 120, 0, 0), -- Highbank Cannon
(@CGUID+178, 49060, 0, 1, 361, 0, -4943.972, -6639.057, 15.53543, 2.96706, 120, 0, 0), -- Highbank Cannon
(@CGUID+179, 49060, 0, 1, 361, 0, -4851.431, -6757.684, 12.39265, 3.839724, 120, 0, 0), -- Highbank Cannon
(@CGUID+180, 49060, 0, 1, 361, 0, -4771.913, -6602.268, 4.161288, 0.9948376, 120, 0, 0), -- Highbank Cannon
(@CGUID+181, 49060, 0, 1, 361, 0, -4735.891, -6626.458, 8.395674, 1.029744, 120, 0, 0), -- Highbank Cannon
(@CGUID+182, 49124, 0, 1, 361, 0, -4871.851, -6601.522, 31.99791, 0.8377581, 120, 0, 0), -- Highbank Marksman
(@CGUID+183, 49124, 0, 1, 361, 0, -4896.823, -6580.74, 20.21382, 2.059489, 120, 0, 0), -- Highbank Marksman
(@CGUID+184, 49124, 0, 1, 361, 0, -4899.583, -6581.436, 16.79153, 1.972222, 120, 0, 0), -- Highbank Marksman
(@CGUID+185, 49124, 0, 1, 361, 0, -4894.087, -6578.321, 20.21381, 2.199115, 120, 0, 0), -- Highbank Marksman
(@CGUID+186, 49124, 0, 1, 361, 0, -4894.668, -6596.194, 43.17696, 2.478368, 120, 0, 0), -- Highbank Marksman
(@CGUID+187, 49124, 0, 1, 361, 0, -4911.479, -6647.521, 32.00031, 4.049164, 120, 0, 0), -- Highbank Marksman
(@CGUID+188, 49124, 0, 1, 361, 0, -4891.944, -6575.346, 16.62649, 2.268928, 120, 0, 0), -- Highbank Marksman
(@CGUID+189, 49124, 0, 1, 361, 0, -4892.488, -6578.738, 20.21383, 2.059489, 120, 0, 0), -- Highbank Marksman
(@CGUID+190, 49124, 0, 1, 361, 0, -4892.269, -6583.832, 43.17997, 2.286381, 120, 0, 0), -- Highbank Marksman
(@CGUID+191, 49124, 0, 1, 361, 0, -4898.962, -6590.753, 43.17576, 2.722714, 120, 0, 0), -- Highbank Marksman
(@CGUID+192, 49124, 0, 1, 361, 0, -4897.858, -6589.358, 43.1778, 2.007129, 120, 0, 0), -- Highbank Marksman
(@CGUID+193, 49124, 0, 1, 361, 0, -4870.972, -6593.064, 43.17777, 0.9599311, 120, 0, 0), -- Highbank Marksman
(@CGUID+194, 49124, 0, 1, 361, 0, -4878.634, -6584.01, 43.17838, 1.570796, 120, 0, 0), -- Highbank Marksman
(@CGUID+195, 49124, 0, 1, 361, 0, -4869.522, -6569.41, 17.39485, 2.303835, 120, 0, 0), -- Highbank Marksman
(@CGUID+196, 49124, 0, 1, 361, 0, -4874.307, -6591.213, 43.17411, 1.256637, 120, 0, 0), -- Highbank Marksman
(@CGUID+197, 49124, 0, 1, 361, 0, -4883.592, -6577.408, 43.17844, 1.413717, 120, 0, 0), -- Highbank Marksman
(@CGUID+198, 49124, 0, 1, 361, 0, -4883.147, -6578.861, 43.1778, 1.32645, 120, 0, 0), -- Highbank Marksman
(@CGUID+199, 49124, 0, 1, 361, 0, -4928.797, -6636.944, 43.17809, 4.08407, 120, 0, 0), -- Highbank Marksman
(@CGUID+200, 49124, 0, 1, 361, 0, -4925.722, -6612.78, 43.17768, 2.635447, 120, 0, 0), -- Highbank Marksman
(@CGUID+201, 49124, 0, 1, 361, 0, -4926.571, -6640.049, 43.17809, 4.485496, 120, 0, 0), -- Highbank Marksman
(@CGUID+202, 49124, 0, 1, 361, 0, -4860.893, -6565.594, 17.39485, 1.937315, 120, 0, 0), -- Highbank Marksman
(@CGUID+203, 49124, 0, 1, 361, 0, -4932.338, -6620.073, 43.1735, 2.792527, 120, 0, 0), -- Highbank Marksman
(@CGUID+204, 49124, 0, 1, 361, 0, -4863.592, -6566.168, 17.39485, 2.008862, 120, 0, 0), -- Highbank Marksman
(@CGUID+205, 49124, 0, 1, 361, 0, -4932.559, -6618.321, 43.17826, 2.827433, 120, 0, 0), -- Highbank Marksman
(@CGUID+206, 49124, 0, 1, 361, 0, -4864.768, -6565.276, 17.39486, 2.076942, 120, 0, 0), -- Highbank Marksman
(@CGUID+207, 49124, 0, 1, 361, 0, -4925.124, -6639.67, 43.17844, 4.24115, 120, 0, 0), -- Highbank Marksman
(@CGUID+208, 49124, 0, 1, 361, 0, -4859.597, -6567.122, 19.70961, 1.623156, 120, 0, 0), -- Highbank Marksman
(@CGUID+209, 49124, 0, 1, 361, 0, -4884.616, -6578.627, 43.1765, 1.570796, 120, 0, 0), -- Highbank Marksman
(@CGUID+210, 49124, 0, 1, 361, 0, -4934.988, -6628.627, 43.17621, 3.944444, 120, 0, 0), -- Highbank Marksman
(@CGUID+211, 49124, 0, 1, 361, 0, -4903.962, -6666.568, 43.17808, 3.961897, 120, 0, 0), -- Highbank Marksman
(@CGUID+212, 49124, 0, 1, 361, 0, -4854.627, -6564.118, 17.39647, 1.867502, 120, 0, 0), -- Highbank Marksman
(@CGUID+213, 49124, 0, 1, 361, 0, -4858.936, -6564.772, 17.39646, 1.818336, 120, 0, 0), -- Highbank Marksman
(@CGUID+214, 49124, 0, 1, 361, 0, -4906.274, -6664.643, 43.17844, 4.13643, 120, 0, 0), -- Highbank Marksman
(@CGUID+215, 49124, 0, 1, 361, 0, -4888.314, -6676.101, 43.1764, 4.607669, 120, 0, 0), -- Highbank Marksman
(@CGUID+216, 49124, 0, 1, 361, 0, -4856.236, -6563.606, 17.39647, 1.762783, 120, 0, 0), -- Highbank Marksman
(@CGUID+217, 49124, 0, 1, 361, 0, -4857.83, -6566.354, 19.71123, 1.780236, 120, 0, 0), -- Highbank Marksman
(@CGUID+218, 49124, 0, 1, 361, 0, -4932.321, -6629.287, 43.1735, 3.717551, 120, 0, 0), -- Highbank Marksman
(@CGUID+219, 49124, 0, 1, 361, 0, -4898.749, -6671.931, 43.1764, 4.066617, 120, 0, 0), -- Highbank Marksman
(@CGUID+220, 49124, 0, 1, 361, 0, -4887.184, -6675.432, 43.17709, 4.555309, 120, 0, 0), -- Highbank Marksman
(@CGUID+221, 49124, 0, 1, 361, 0, -4899.927, -6670.893, 43.17716, 4.118977, 120, 0, 0), -- Highbank Marksman
(@CGUID+222, 49124, 0, 1, 361, 0, -4934.42, -6629.702, 43.17704, 3.892084, 120, 0, 0), -- Highbank Marksman
(@CGUID+223, 49124, 0, 1, 361, 0, -4904.874, -6664.781, 43.17623, 4.08407, 120, 0, 0), -- Highbank Marksman
(@CGUID+224, 49124, 0, 1, 361, 0, -4857.25, -6564.518, 17.39647, 1.692969, 120, 0, 0), -- Highbank Marksman
(@CGUID+225, 49124, 0, 1, 361, 0, -4895.522, -6675.936, 43.17666, 3.857178, 120, 0, 0), -- Highbank Marksman
(@CGUID+226, 49124, 0, 1, 361, 0, -4829.221, -6570.431, 17.40821, 1.413717, 120, 0, 0), -- Highbank Marksman
(@CGUID+227, 49124, 0, 1, 361, 0, -4838.253, -6566.997, 17.40823, 4.834562, 120, 0, 0), -- Highbank Marksman
(@CGUID+228, 49124, 0, 1, 361, 0, -4893.075, -6679.771, 43.17799, 3.961897, 120, 0, 0), -- Highbank Marksman
(@CGUID+229, 49124, 0, 1, 361, 0, -4826.651, -6570.306, 17.40815, 1.186824, 120, 0, 0), -- Highbank Marksman
(@CGUID+230, 49124, 0, 1, 361, 0, -4894.219, -6676.283, 43.17422, 3.909538, 120, 0, 0), -- Highbank Marksman
(@CGUID+231, 49124, 0, 1, 361, 0, -4848.613, -6562.818, 17.39647, 1.500983, 120, 0, 0), -- Highbank Marksman
(@CGUID+232, 49124, 0, 1, 361, 0, -4848.019, -6563.757, 17.39647, 1.466077, 120, 0, 0), -- Highbank Marksman
(@CGUID+233, 49124, 0, 1, 361, 0, -4842.681, -6565.705, 17.40823, 1.256637, 120, 0, 0), -- Highbank Marksman
(@CGUID+234, 49124, 0, 1, 361, 0, -4939.939, -6624.24, 43.1776, 3.054326, 120, 0, 0), -- Highbank Marksman
(@CGUID+235, 49124, 0, 1, 361, 0, -4838.45, -6565.628, 17.40824, 1.27409, 120, 0, 0), -- Highbank Marksman
(@CGUID+236, 49124, 0, 1, 361, 0, -4893.932, -6678.394, 43.17781, 3.769911, 120, 0, 0), -- Highbank Marksman
(@CGUID+237, 49124, 0, 1, 361, 0, -4822.162, -6572.443, 17.40814, 1.361357, 120, 0, 0), -- Highbank Marksman
(@CGUID+238, 49124, 0, 1, 361, 0, -4805.624, -6578.103, 17.43129, 1.347766, 120, 0, 0), -- Highbank Marksman
(@CGUID+239, 49124, 0, 1, 361, 0, -4808.149, -6577.056, 17.4313, 1.500983, 120, 0, 0), -- Highbank Marksman
(@CGUID+240, 49124, 0, 1, 361, 0, -4817.188, -6573.338, 17.40813, 1.32645, 120, 0, 0), -- Highbank Marksman
(@CGUID+241, 49124, 0, 1, 361, 0, -4801.628, -6579.016, 17.43129, 1.361357, 120, 0, 0), -- Highbank Marksman
(@CGUID+242, 49124, 0, 1, 361, 0, -4800.116, -6578.097, 17.43129, 1.32645, 120, 0, 0), -- Highbank Marksman
(@CGUID+243, 49124, 0, 1, 361, 0, -4815.559, -6575.043, 17.40813, 1.408402, 120, 0, 0), -- Highbank Marksman
(@CGUID+244, 49124, 0, 1, 361, 0, -4803.905, -6577.835, 17.43129, 1.48353, 120, 0, 0), -- Highbank Marksman
(@CGUID+245, 49124, 0, 1, 361, 0, -4799.439, -6578.594, 17.43129, 1.361357, 120, 0, 0), -- Highbank Marksman
(@CGUID+246, 49124, 0, 1, 361, 0, -4816.351, -6573.252, 17.40813, 1.27409, 120, 0, 0), -- Highbank Marksman
(@CGUID+247, 49124, 0, 1, 361, 0, -4742.213, -6618.797, 11.7435, 1.134464, 120, 0, 0), -- Highbank Marksman
(@CGUID+248, 49124, 0, 1, 361, 0, -4796.13, -6581.353, 17.43128, 0.5759587, 120, 0, 0), -- Highbank Marksman
(@CGUID+249, 49124, 0, 1, 361, 0, -4740.385, -6618.684, 11.7437, 1.27409, 120, 0, 0), -- Highbank Marksman
(@CGUID+250, 49124, 0, 1, 361, 0, -4715.115, -6642.762, 17.75548, 0.7679449, 120, 0, 0), -- Highbank Marksman
(@CGUID+251, 49124, 0, 1, 361, 0, -4788.84, -6770.809, 17.75029, 4.782202, 120, 0, 0), -- Highbank Marksman
(@CGUID+252, 49124, 0, 1, 361, 0, -4796.128, -6769.768, 20.07062, 4.747295, 120, 0, 0), -- Highbank Marksman
(@CGUID+253, 49124, 0, 1, 361, 0, -4714.667, -6641.083, 17.75549, 0.8901179, 120, 0, 0), -- Highbank Marksman
(@CGUID+254, 49124, 0, 1, 361, 0, -4713.665, -6642.724, 17.75548, 0.9424778, 120, 0, 0), -- Highbank Marksman
(@CGUID+255, 49124, 0, 1, 361, 0, -4719.038, -6637.167, 17.7555, 0.6632251, 120, 0, 0), -- Highbank Marksman
(@CGUID+256, 49124, 0, 1, 361, 0, -4799.752, -6771.229, 17.75587, 4.856599, 120, 0, 0), -- Highbank Marksman
(@CGUID+257, 49124, 0, 1, 361, 0, -4719.219, -6638.894, 17.75549, 0.715585, 120, 0, 0), -- Highbank Marksman
(@CGUID+258, 49124, 0, 1, 361, 0, -4806.438, -6773.146, 17.75588, 4.947245, 120, 0, 0), -- Highbank Marksman
(@CGUID+259, 49124, 0, 1, 361, 0, -4793.799, -6771.503, 17.7503, 4.694936, 120, 0, 0), -- Highbank Marksman
(@CGUID+260, 49124, 0, 1, 361, 0, -4726.609, -6642.071, 41.75085, 0.9250245, 120, 0, 0), -- Highbank Marksman
(@CGUID+261, 49124, 0, 1, 361, 0, -4788.139, -6771.971, 17.75028, 4.782202, 120, 0, 0), -- Highbank Marksman
(@CGUID+262, 49124, 0, 1, 361, 0, -4789.948, -6771.743, 17.75029, 4.925191, 120, 0, 0), -- Highbank Marksman
(@CGUID+263, 49124, 0, 1, 361, 0, -4764.847, -6769.288, 17.75254, 4.828381, 120, 0, 0), -- Highbank Marksman
(@CGUID+264, 49124, 0, 1, 361, 0, -4772.035, -6769.894, 17.75255, 4.830969, 120, 0, 0), -- Highbank Marksman
(@CGUID+265, 49124, 0, 1, 361, 0, -4757.74, -6768.764, 17.67669, 4.817109, 120, 0, 0), -- Highbank Marksman
(@CGUID+266, 49124, 0, 1, 361, 0, -4698.385, -6641.441, 44.56483, 0.9250245, 120, 0, 0), -- Highbank Marksman
(@CGUID+267, 49124, 0, 1, 361, 0, -4783.781, -6770.622, 17.75027, 4.904375, 120, 0, 0), -- Highbank Marksman
(@CGUID+268, 49124, 0, 1, 361, 0, -4701.931, -6669.391, 44.56463, 5.218534, 120, 0, 0), -- Highbank Marksman
(@CGUID+269, 49124, 0, 1, 361, 0, -4776.853, -6770.25, 17.75256, 4.834562, 120, 0, 0), -- Highbank Marksman
(@CGUID+270, 49124, 0, 1, 361, 0, -4782.37, -6771.927, 17.75027, 4.835389, 120, 0, 0), -- Highbank Marksman
(@CGUID+271, 49124, 0, 1, 361, 0, -4770.622, -6770.646, 17.75255, 4.677482, 120, 0, 0), -- Highbank Marksman
(@CGUID+272, 49124, 0, 1, 361, 0, -4755.179, -6768.944, 17.67669, 5.009095, 120, 0, 0), -- Highbank Marksman
(@CGUID+273, 49124, 0, 1, 361, 0, -4766.755, -6769.691, 17.75254, 4.984589, 120, 0, 0), -- Highbank Marksman
(@CGUID+274, 49124, 0, 1, 361, 0, -4692.797, -6642.499, 44.56532, 1.291544, 120, 0, 0), -- Highbank Marksman
(@CGUID+275, 49124, 0, 1, 361, 0, -4695.674, -6672.865, 17.79168, 0.122173, 120, 0, 0), -- Highbank Marksman
(@CGUID+276, 49124, 0, 1, 361, 0, -4705.778, -6640.573, 44.56519, 1.22173, 120, 0, 0), -- Highbank Marksman
(@CGUID+277, 49124, 0, 1, 361, 0, -4765.722, -6770.365, 17.75254, 5.009095, 120, 0, 0), -- Highbank Marksman
(@CGUID+278, 49124, 0, 1, 361, 0, -4753.882, -6769.618, 17.67669, 4.660029, 120, 0, 0), -- Highbank Marksman
(@CGUID+279, 49124, 0, 1, 361, 0, -4694.249, -6674.056, 17.79169, 0.4537856, 120, 0, 0), -- Highbank Marksman
(@CGUID+280, 49124, 0, 1, 361, 0, -4690.639, -6643.755, 44.56532, 0.8028514, 120, 0, 0), -- Highbank Marksman
(@CGUID+281, 49124, 0, 1, 361, 0, -4690.816, -6642.115, 44.56178, 0.6981317, 120, 0, 0), -- Highbank Marksman
(@CGUID+282, 49124, 0, 1, 361, 0, -4695.203, -6678.736, 17.79169, 0.1396263, 120, 0, 0), -- Highbank Marksman
(@CGUID+283, 49124, 0, 1, 361, 0, -4693.34, -6677.972, 17.79169, 6.2769, 120, 0, 0), -- Highbank Marksman
(@CGUID+284, 49124, 0, 1, 361, 0, -4696.313, -6690.09, 17.83895, 6.073746, 120, 0, 0), -- Highbank Marksman
(@CGUID+285, 49124, 0, 1, 361, 0, -4696.738, -6691.088, 17.83895, 6.178465, 120, 0, 0), -- Highbank Marksman
(@CGUID+286, 49124, 0, 1, 361, 0, -4698.49, -6695.385, 17.83896, 5.846853, 120, 0, 0), -- Highbank Marksman
(@CGUID+287, 49124, 0, 1, 361, 0, -4685.59, -6656.726, 44.56558, 5.926285, 120, 0, 0), -- Highbank Marksman
(@CGUID+288, 49124, 0, 1, 361, 0, -4698.686, -6705.922, 17.80357, 6.161012, 120, 0, 0), -- Highbank Marksman
(@CGUID+289, 49124, 0, 1, 361, 0, -4699.111, -6707.309, 17.80358, 6.230825, 120, 0, 0), -- Highbank Marksman
(@CGUID+290, 49124, 0, 1, 361, 0, -4689.986, -6664.109, 44.56484, 0.2875007, 120, 0, 0), -- Highbank Marksman
(@CGUID+291, 49124, 0, 1, 361, 0, -4719.931, -6742.814, 36.99194, 6.003932, 120, 0, 0), -- Highbank Marksman
(@CGUID+292, 49124, 0, 1, 361, 0, -4749.717, -6769.597, 17.67668, 5.009095, 120, 0, 0), -- Highbank Marksman
(@CGUID+293, 49124, 0, 1, 361, 0, -4748.087, -6768.3, 17.67668, 4.712389, 120, 0, 0), -- Highbank Marksman
(@CGUID+294, 49124, 0, 1, 361, 0, -4701.045, -6712.963, 17.80359, 6.072475, 120, 0, 0), -- Highbank Marksman
(@CGUID+295, 49124, 0, 1, 361, 0, -4685.236, -6658.146, 44.56473, 5.645668, 120, 0, 0), -- Highbank Marksman
(@CGUID+296, 49124, 0, 1, 361, 0, -4699.005, -6700.484, 17.83897, 6.230825, 120, 0, 0), -- Highbank Marksman
(@CGUID+297, 49124, 0, 1, 361, 0, -4700.965, -6711.535, 17.80359, 6.073746, 120, 0, 0), -- Highbank Marksman
(@CGUID+298, 49124, 0, 1, 361, 0, -4744.54, -6766.707, 44.81065, 4.014257, 120, 0, 0), -- Highbank Marksman
(@CGUID+299, 49124, 0, 1, 361, 0, -4697.318, -6696.677, 17.83896, 6.003932, 120, 0, 0), -- Highbank Marksman
(@CGUID+300, 49124, 0, 1, 361, 0, -4695.415, -6689.337, 17.83894, 5.986479, 120, 0, 0), -- Highbank Marksman
(@CGUID+301, 49124, 0, 1, 361, 0, -4696.588, -6694.999, 17.83896, 5.951573, 120, 0, 0), -- Highbank Marksman
(@CGUID+302, 49124, 0, 1, 361, 0, -4711.21, -6749.609, 17.31667, 5.654867, 120, 0, 0), -- Highbank Marksman
(@CGUID+303, 49124, 0, 1, 361, 0, -4703.656, -6734.955, 17.32399, 0.05235988, 120, 0, 0), -- Highbank Marksman
(@CGUID+304, 49124, 0, 1, 361, 0, -4710.894, -6751.096, 17.31668, 5.497787, 120, 0, 0), -- Highbank Marksman
(@CGUID+305, 49124, 0, 1, 361, 0, -4705.262, -6740.109, 17.32399, 6.126106, 120, 0, 0), -- Highbank Marksman
(@CGUID+306, 49124, 0, 1, 361, 0, -4709.497, -6749.588, 17.31667, 5.742133, 120, 0, 0), -- Highbank Marksman
(@CGUID+307, 49124, 0, 1, 361, 0, -4701.88, -6734.179, 17.324, 6.230825, 120, 0, 0), -- Highbank Marksman
(@CGUID+308, 49124, 0, 1, 361, 0, -4717.962, -6757.772, 44.81141, 0.01745329, 120, 0, 0), -- Highbank Marksman
(@CGUID+309, 49124, 0, 1, 361, 0, -4717.894, -6759.405, 44.8119, 6.264805, 120, 0, 0), -- Highbank Marksman
(@CGUID+310, 49124, 0, 1, 361, 0, -4709.478, -6745.175, 17.31666, 5.986479, 120, 0, 0), -- Highbank Marksman
(@CGUID+311, 49124, 0, 1, 361, 0, -4702.238, -6735.708, 17.324, 6.152756, 120, 0, 0), -- Highbank Marksman
(@CGUID+312, 49124, 0, 1, 361, 0, -4714.035, -6753.662, 17.31667, 5.759586, 120, 0, 0), -- Highbank Marksman
(@CGUID+313, 49124, 0, 1, 361, 0, -4715.906, -6753.672, 17.31667, 5.51524, 120, 0, 0), -- Highbank Marksman
(@CGUID+314, 49124, 0, 1, 361, 0, -4703.387, -6739.825, 17.324, 6.073746, 120, 0, 0), -- Highbank Marksman
(@CGUID+315, 49124, 0, 1, 361, 0, -4718.691, -6754.564, 44.81155, 6.260536, 120, 0, 0), -- Highbank Marksman
(@CGUID+316, 49124, 0, 1, 361, 0, -4735.078, -6776.948, 44.81028, 4.729842, 120, 0, 0), -- Highbank Marksman
(@CGUID+317, 49124, 0, 1, 361, 0, -4726.785, -6778.25, 44.811, 5.497787, 120, 0, 0), -- Highbank Marksman
(@CGUID+318, 49124, 0, 1, 361, 0, -4715.955, -6766.99, 44.81105, 0.08726646, 120, 0, 0), -- Highbank Marksman
(@CGUID+319, 49124, 0, 1, 361, 0, -4728.33, -6778.58, 44.81138, 5.061455, 120, 0, 0), -- Highbank Marksman
(@CGUID+320, 49124, 0, 1, 361, 0, -4715.963, -6768.747, 44.81041, 5.77704, 120, 0, 0), -- Highbank Marksman
(@CGUID+321, 49135, 765, 1, 361, 0, -5.014006, -0.163617, -17.7251, 1.58825, 120, 0, 0), -- Skyshredder Turret
(@CGUID+322, 49135, 765, 1, 361, 0, -9.295275, -0.520407, -16.08218, 1.745329, 120, 0, 0), -- Skyshredder Turret
(@CGUID+323, 49135, 765, 1, 361, 0, 14.86789, -4.727139, -22.75339, 0.9773844, 120, 0, 0), -- Skyshredder Turret
(@CGUID+324, 49135, 765, 1, 361, 0, -20.23349, -5.56366, -13.43173, 1.815142, 120, 0, 0), -- Skyshredder Turret
(@CGUID+325, 49135, 765, 1, 361, 0, -22.11486, -7.76682, -13.12884, 1.815142, 120, 0, 0), -- Skyshredder Turret
(@CGUID+326, 49142, 765, 1, 361, 0, 7.535932, 0.734553, -22.89209, 1.727876, 120, 0, 0), -- Skyshredder Target Bunny
(@CGUID+327, 49142, 765, 1, 361, 0, -7.193839, 0.2175903, -23.95871, 1.727876, 120, 0, 0), -- Skyshredder Target Bunny
(@CGUID+328, 49142, 765, 1, 361, 0, 0.8367572, 0.1771528, -20.15524, 1.727876, 120, 0, 0), -- Skyshredder Target Bunny
(@CGUID+329, 49142, 765, 1, 361, 0, -11.81855, -0.8221215, -18.22282, 1.727876, 120, 0, 0), -- Skyshredder Target Bunny
(@CGUID+330, 49142, 765, 1, 361, 0, -1.96348, -1.176578, -16.04053, 1.727876, 120, 0, 0), -- Skyshredder Target Bunny
(@CGUID+331, 49142, 765, 1, 361, 0, 4.284857, -1.283973, -15.64779, 2.042035, 120, 0, 0), -- Skyshredder Target Bunny
(@CGUID+332, 49142, 765, 1, 361, 0, 18.37795, -4.111235, -23.86238, 1.727876, 120, 0, 0), -- Skyshredder Target Bunny
(@CGUID+333, 49142, 765, 1, 361, 0, 6.042887, -1.167839, -11.6026, 1.727876, 120, 0, 0), -- Skyshredder Target Bunny
(@CGUID+334, 49142, 765, 1, 361, 0, 14.78969, -3.998745, -20.17596, 1.727876, 120, 0, 0), -- Skyshredder Target Bunny
(@CGUID+335, 49142, 765, 1, 361, 0, -10.76226, -1.567489, -11.68963, 1.727876, 120, 0, 0), -- Skyshredder Target Bunny
(@CGUID+336, 49142, 765, 1, 361, 0, -15.91676, -4.869974, -13.59666, 1.727876, 120, 0, 0), -- Skyshredder Target Bunny
(@CGUID+337, 49142, 765, 1, 361, 0, -21.20465, -7.396579, -10.57561, 1.727876, 120, 0, 0), -- Skyshredder Target Bunny
(@CGUID+338, 49143, 0, 1, 361, 0, -4867.646, -6593.005, 9.500094, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+339, 49143, 0, 1, 361, 0, -4880.387, -6598.92, 10.91306, 1.413717, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+340, 49143, 0, 1, 361, 0, -4862.731, -6635.205, 10.93797, 3.804818, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+341, 49143, 0, 1, 361, 0, -4863.634, -6635.005, 10.93805, 5.096361, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+342, 49143, 0, 1, 361, 0, -4918.851, -6622.646, 19.0485, 5.096361, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+343, 49143, 0, 1, 361, 0, -4842.306, -6610.689, 9.500094, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+344, 49143, 0, 1, 361, 0, -4875.646, -6595.785, 31.99581, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+345, 49143, 0, 1, 361, 0, -4842.205, -6609.771, 9.500094, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+346, 49143, 0, 1, 361, 0, -4919.245, -6631.599, 10.91306, 2.792527, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+347, 49143, 0, 1, 361, 0, -4874.726, -6595.724, 31.99574, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+348, 49143, 0, 1, 361, 0, -4888.127, -6655.463, 31.99576, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+349, 49143, 0, 1, 361, 0, -4881.149, -6667.182, 10.91675, 5.096361, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+350, 49143, 0, 1, 361, 0, -4887.101, -6655.022, 31.99615, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+351, 49143, 0, 1, 361, 0, -4883.347, -6584.318, 31.99664, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+352, 49143, 0, 1, 361, 0, -4887.309, -6655.948, 31.99609, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+353, 49143, 0, 1, 361, 0, -4880.662, -6676.418, 9.500094, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+354, 49143, 0, 1, 361, 0, -4899.809, -6665.538, 31.99704, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+355, 49143, 0, 1, 361, 0, -4923.835, -6633.736, 31.99592, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+356, 49143, 0, 1, 361, 0, -4851.628, -6660.311, 8.71979, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+357, 49143, 0, 1, 361, 0, -4835.569, -6625.913, 9.500101, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+358, 49143, 0, 1, 361, 0, -4842.788, -6591.877, 9.500094, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+359, 49143, 0, 1, 361, 0, -4866.378, -6669.944, 8.944811, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+360, 49143, 0, 1, 361, 0, -4924.708, -6633.707, 31.99792, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+361, 49143, 0, 1, 361, 0, -4843.212, -6592.747, 9.500094, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+362, 49143, 0, 1, 361, 0, -4919.674, -6667.684, 9.500092, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+363, 49143, 0, 1, 361, 0, -4910.729, -6671.753, 9.498888, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+364, 49143, 0, 1, 361, 0, -4845.463, -6577.297, 9.500094, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+365, 49143, 0, 1, 361, 0, -4823.276, -6652.905, 6.233095, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+366, 49143, 0, 1, 361, 0, -4889.272, -6689.726, 9.500092, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+367, 49143, 0, 1, 361, 0, -4813.943, -6588.537, 9.500094, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+368, 49143, 0, 1, 361, 0, -4874.406, -6701.108, 5.184727, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+369, 49143, 0, 1, 361, 0, -4788.728, -6616.875, 5.215233, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+370, 49143, 0, 1, 361, 0, -4865.894, -6717.349, 5.18372, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+371, 49143, 0, 1, 361, 0, -4939.877, -6713.965, 7.955153, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+372, 49143, 0, 1, 361, 0, -4861.828, -6730.491, 10.21786, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+373, 49143, 0, 1, 361, 0, -4877.955, -6739.215, 5.142416, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+374, 49143, 0, 1, 361, 0, -4827.172, -6713.448, 5.240479, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+375, 49143, 0, 1, 361, 0, -4831.196, -6728.155, 10.65065, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+376, 49143, 0, 1, 361, 0, -4830.728, -6728.929, 10.65066, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+377, 49143, 0, 1, 361, 0, -4808.314, -6713.037, 6.285276, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+378, 49143, 0, 1, 361, 0, -4802.708, -6708.491, 5.154474, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+379, 49143, 0, 1, 361, 0, -4818.249, -6758.415, 35.53225, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+380, 49143, 0, 1, 361, 0, -4800.042, -6743.958, 9.500101, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+381, 49143, 0, 1, 361, 0, -4818.299, -6757.495, 35.44366, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+382, 49143, 0, 1, 361, 0, -4788.865, -6730.476, 9.500101, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+383, 49143, 0, 1, 361, 0, -4818.932, -6757.957, 35.49652, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+384, 49143, 0, 1, 361, 0, -4830.618, -6748.53, 11.60993, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+385, 49143, 0, 1, 361, 0, -4920.269, -6740.675, 5.681458, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+386, 49143, 0, 1, 361, 0, -4909.526, -6745.12, 5.917505, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+387, 49143, 0, 1, 361, 0, -4715.974, -6721.628, 28.62538, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+388, 49143, 0, 1, 361, 0, -4747.738, -6690.821, 9.23926, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+389, 49143, 0, 1, 361, 0, -4732.146, -6764.679, 44.57782, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+390, 49143, 0, 1, 361, 0, -4723.049, -6706.037, 12.89989, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+391, 49143, 0, 1, 361, 0, -4739.993, -6770.368, 7.381551, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+392, 49143, 0, 1, 361, 0, -4731.497, -6764.17, 44.57782, 5.759586, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+393, 49143, 0, 1, 361, 0, -4740.202, -6771.323, 7.381551, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+394, 49143, 0, 1, 361, 0, -4728.476, -6763.787, 44.57781, 5.096361, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+395, 49143, 0, 1, 361, 0, -4744.495, -6718.87, 9.500101, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+396, 49143, 0, 1, 361, 0, -4728.774, -6762.896, 44.57782, 4.118977, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+397, 49143, 0, 1, 361, 0, -4716.628, -6721.309, 28.6064, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+398, 49143, 0, 1, 361, 0, -4719.109, -6740.814, 9.458838, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+399, 49143, 0, 1, 361, 0, -4739.424, -6770.997, 7.381551, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+400, 49143, 0, 1, 361, 0, -4732.26, -6763.799, 44.57782, 5.096361, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+401, 49143, 0, 1, 361, 0, -4715.936, -6720.944, 28.55895, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+402, 49143, 0, 1, 361, 0, -4706.91, -6681.728, 9.49799, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+403, 49143, 0, 1, 361, 0, -4702.71, -6655.493, 44.33189, 5.288348, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+404, 49143, 0, 1, 361, 0, -4690.679, -6654.757, 7.135621, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+405, 49143, 0, 1, 361, 0, -4702.728, -6654.793, 44.33189, 1.902409, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+406, 49143, 0, 1, 361, 0, -4690.394, -6655.549, 7.135621, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+407, 49143, 0, 1, 361, 0, -4702.082, -6655.04, 44.33189, 5.61996, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+408, 49143, 0, 1, 361, 0, -4689.762, -6654.906, 7.135621, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+409, 49143, 0, 1, 361, 0, -4729.297, -6643.441, 9.440876, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+410, 49143, 0, 1, 361, 0, -4793.233, -6754.016, 11.90074, 0, 120, 0, 0), -- Cannon Powder Barrel
(@CGUID+411, 49144, 0, 1, 361, 0, -4733.196, -6761.229, 7.38155, 0, 120, 0, 0), -- Highbank Tower Bomb Controller
(@CGUID+412, 49144, 0, 1, 361, 0, -4703.302, -6656.415, 7.135619, 0, 120, 0, 0), -- Highbank Tower Bomb Controller
(@CGUID+413, 49182, 0, 1, 361, 0, -4974.396, -6577.764, 41.85179, 2.660037, 120, 0, 0), -- Skyshredder Landing Bunny Aura: 94210
(@CGUID+414, 49198, 0, 1, 361, 0, -4849.49, -6594.755, 9.500094, 1.239184, 120, 0, 0), -- Flintlocke Cannon Controller Bunny
(@CGUID+415, 49225, 765, 1, 361, 0, -4.525865, -11.52265, -22.59468, 0, 120, 0, 0), -- Skyshredder Bomb Bunny
(@CGUID+416, 49225, 765, 1, 361, 0, -1.984066, -7.811529, -19.59087, 0, 120, 0, 0), -- Skyshredder Bomb Bunny
(@CGUID+417, 49225, 765, 1, 361, 0, 0.8204566, -6.088042, -23.64387, 0, 120, 0, 0), -- Skyshredder Bomb Bunny
(@CGUID+418, 49225, 765, 1, 361, 0, 6.211529, -6.665619, -23.55482, 0, 120, 0, 0), -- Skyshredder Bomb Bunny
(@CGUID+419, 49225, 765, 1, 361, 0, 15.10693, -9.888285, -23.94149, 0, 120, 0, 0), -- Skyshredder Bomb Bunny
(@CGUID+420, 49225, 765, 1, 361, 0, 9.597854, -7.801392, -23.50033, 0, 120, 0, 0), -- Skyshredder Bomb Bunny
(@CGUID+421, 49225, 765, 1, 361, 0, 2.202101, -10.15354, -23.61975, 0, 120, 0, 0), -- Skyshredder Bomb Bunny
(@CGUID+422, 49225, 765, 1, 361, 0, 13.13324, -5.692163, -24.16053, 0, 120, 0, 0), -- Skyshredder Bomb Bunny
(@CGUID+423, 49225, 765, 1, 361, 0, -7.325118, -7.352751, -21.88816, 0, 120, 0, 0), -- Skyshredder Bomb Bunny
(@CGUID+424, 49225, 765, 1, 361, 0, -4.210377, -3.89003, -22.22782, 0, 120, 0, 0), -- Skyshredder Bomb Bunny
(@CGUID+425, 49252, 0, 1, 361, 0, -4944.655, -6709.207, 14.28477, 2.513274, 120, 0, 0), -- Fargo Flintlocke
(@CGUID+426, 49284, 0, 1, 0, 551, -4851.715, -6646.316, 14.09782, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+427, 49284, 0, 1, 0, 551, -4906.946, -6669.528, 14.11939, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+428, 49284, 0, 1, 0, 551, -4897.978, -6674.21, 13.93016, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+429, 49284, 0, 1, 0, 551, -4878.755, -6561.578, 9.696568, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+430, 49284, 0, 1, 0, 551, -4944.302, -6620.245, 10.51468, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+431, 49284, 0, 1, 0, 551, -4921.703, -6660.972, 34.13746, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+432, 49284, 0, 1, 0, 551, -4895.497, -6589.943, 54.57689, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+433, 49284, 0, 1, 0, 551, -4889.906, -6687.99, 15.22129, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+434, 49284, 0, 1, 0, 551, -4886.809, -6579.644, 50.21634, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+435, 49284, 0, 1, 0, 551, -4870.092, -6687.974, 11.58083, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+436, 49284, 0, 1, 0, 551, -4929.96, -6663.448, 32.34312, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+437, 49284, 0, 1, 0, 551, -4865.368, -6551.359, 4.935884, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+438, 49284, 0, 1, 0, 551, -4927.703, -6622.899, 60.51099, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+439, 49284, 0, 1, 0, 551, -4807.827, -6564.821, 7.087519, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+440, 49284, 0, 1, 0, 551, -4799.939, -6608.561, 32.55735, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+441, 49284, 0, 1, 0, 551, -4830.988, -6550.703, 8.537516, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+442, 49284, 0, 1, 0, 551, -4781.993, -6599.788, 21.0806, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+443, 49284, 0, 1, 0, 551, -4848.628, -6711.818, 10.67312, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+444, 49284, 0, 1, 0, 551, -4785.099, -6581.592, 3.975582, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+445, 49284, 0, 1, 0, 551, -4918.778, -6745.229, 50.56202, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+446, 49284, 0, 1, 0, 551, -4934.387, -6728.221, 33.45486, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+447, 49284, 0, 1, 0, 551, -4921.257, -6746.452, 39.98219, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+448, 49284, 0, 1, 0, 551, -4741.231, -6636.281, 14.1121, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+449, 49284, 0, 1, 0, 551, -4847.583, -6741.29, 21.01917, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+450, 49284, 0, 1, 0, 551, -4744.333, -6620.194, 10.81754, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+451, 49284, 0, 1, 0, 551, -4856.147, -6727.627, 11.60872, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+452, 49284, 0, 1, 0, 551, -4802.162, -6559.597, 4.081532, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+453, 49284, 0, 1, 0, 551, -4800.813, -6739.535, 18.83227, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+454, 49284, 0, 1, 0, 551, -4851.276, -6782.861, 11.87396, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+455, 49284, 0, 1, 0, 551, -4845.663, -6756.868, 33.40289, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+456, 49284, 0, 1, 0, 551, -4824.681, -6779.333, 22.82185, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+457, 49284, 0, 1, 0, 551, -4925.278, -6784.944, 20.96374, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+458, 49284, 0, 1, 0, 551, -4928.772, -6784.042, 18.60542, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+459, 49284, 0, 1, 0, 551, -4721.703, -6630.809, 23.99425, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+460, 49284, 0, 1, 0, 551, -4788.491, -6751.085, 35.46449, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+461, 49284, 0, 1, 0, 551, -4720.771, -6702.78, 36.92118, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+462, 49284, 0, 1, 0, 551, -4702.684, -6683.25, 16.93664, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+463, 49284, 0, 1, 0, 551, -4948.484, -6789.535, 39.56691, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+464, 49284, 0, 1, 0, 551, -4783.587, -6782.713, 8.815172, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+465, 49284, 0, 1, 0, 551, -4805.45, -6790.849, 9.022331, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+466, 49284, 0, 1, 0, 551, -4778.243, -6789.359, 10.54205, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+467, 49284, 0, 1, 0, 551, -4699.082, -6654.424, 69.41505, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+468, 49284, 0, 1, 0, 551, -4693.957, -6646.874, 58.67391, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+469, 49284, 0, 1, 0, 551, -4740.243, -6765.854, 58.73026, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+470, 49284, 0, 1, 0, 551, -4678.556, -6657.087, 6.744792, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+471, 49284, 0, 1, 0, 551, -4681.33, -6652.13, 4.733746, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+472, 49284, 0, 1, 0, 551, -4696.625, -6720.249, 33.73843, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+473, 49284, 0, 1, 0, 551, -4745.075, -6779.853, 7.330765, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+474, 49284, 0, 1, 0, 551, -4714.646, -6777.749, 5.225178, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+475, 49284, 0, 1, 0, 551, -4718.431, -6765.33, 56.69941, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+476, 49284, 0, 1, 0, 551, -4687.439, -6717.503, 5.221254, 0, 120, 0, 0), -- Highbank Fire Bunny
(@CGUID+477, 49380, 0, 1, 361, 0, -4876.143, -6643.444, 10.93719, 0, 120, 0, 0), -- Highbank Keep Bomb Controller
(@CGUID+478, 49381, 0, 1, 361, 0, -4925.111, -6736.26, 5.503531, 0, 120, 0, 0), -- Highbank Boat Bomb Controller
(@CGUID+479, 49631, 0, 1, 361, 0, -4743.17, -6626.766, 11.20078, 0, 120, 0, 0), -- Highbank Cannon Bunny
(@CGUID+480, 49631, 0, 1, 361, 0, -4704.707, -6663.073, 45.50048, 0, 120, 0, 0), -- Highbank Cannon Bunny
(@CGUID+481, 49631, 0, 1, 361, 0, -4690.524, -6654.535, 46.11868, 0, 120, 0, 0), -- Highbank Cannon Bunny
(@CGUID+482, 49631, 0, 1, 361, 0, -4740.045, -6761.733, 45.72603, 0, 120, 0, 0), -- Highbank Cannon Bunny
(@CGUID+483, 49631, 0, 1, 361, 0, -4727.505, -6771.943, 45.73158, 0, 120, 0, 0), -- Highbank Cannon Bunny
(@CGUID+484, 50268, 0, 1, 361, 0, -5013.684, -6764.203, 44.70234, 2.740167, 120, 0, 0), -- Krazzworks Gyrocopter
(@CGUID+485, 50300, 0, 1, 361, 0, -4934.778, -6730.375, 31.70805, 1.396263, 120, 0, 0), -- Flintlocke's Seaplane
(@CGUID+486, 50360, 0, 1, 361, 0, -4855.151, -6588.33, 9.500094, 4.45059, 120, 0, 0), -- "Doc" Schweitzer
(@CGUID+487, 53550, 765, 1, 361, 0, -5.14235, -4.511819, -17.60761, 4.712389, 120, 0, 0); -- Skyshredder Landing Location Bunny

UPDATE `creature_template` SET `flags_extra`=128, `InhabitType`=4 WHERE `entry` IN (49144,49182,49198,49284,49380,49381,49631,53550);
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (49060,50268,15631);

DELETE FROM `creature_template_addon` WHERE `entry` IN (15631,49003,49004,49005,49008,49009,49020,49022,49023,49024,49028,49124,49143,49182,49252,50268,50300,50360,49284);
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(15631,0,1,0, '25824'),(49003,0,257,0, ''),(49004,0,256,0, ''),(49005,0,258,0, '94218'),(49008,0,1,333, ''),(49009,0,1,214, ''),
(49020,0,2,214, ''),(49022,0,1,333, ''),(49023,0,1,333, ''),(49024,0,2,214, ''),(49028,0,1,333, '10022'),(49124,0,2,385, ''),(49143,0,1,0, '85549'),
(49182,0,257,0, '94210'),(49252,0,257,0, '83305'),(50268,0,1,0, '88906'),(50300,0,1,0, '93393'),(50360,0,1,0, '48168'),(49284,0,1,0, '95843 84020');

-- Pathing for Skyshredder Crewmember Entry: 49006 'TDB FORMAT' 
SET @NPC := @CGUID+78;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3.536133,`position_y`=-12.3042,`position_z`=-17.85204 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3.536133,-12.3042,-17.85204,0,3000,1,0,100,0),
(@PATH,2,-16.20313,-9.192383,-15.37517,0,3000,1,0,100,0),
(@PATH,3,1.689453,-3.48584,-17.93687,0,3000,1,0,100,0),
(@PATH,4,-16.20337,-9.192383,-15.3751,0,3000,0,0,100,0);

-- Gameobject spawns for highbank and Obsidion Breakers all phases
SET @OGUID   := 233404;
DELETE FROM `gameobject` WHERE `id`=190192 and `map`=0;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID AND @OGUID+70;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseId`,`PhaseGroup`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@OGUID+0,204952,0,1,0,551,-4863.13,-6670.431,8.61997,2.251473,0,0,0.902585,0.4305117,120,255,1), -- Mailbox
(@OGUID+1,205111,0,1,361,0,-4856.922,-6589.8,9.416761,4.956738,0,0,-0.6156607,0.7880114,120,255,1), -- Stormwind Crate
(@OGUID+2,205248,0,1,0,551,-4892.11,-6624.21,10.8372,5.410522,0,0,-0.4226179,0.9063079,120,255,1), -- Stormwind Portal
(@OGUID+3,207259,0,1,361,0,-4885.202,-6628.603,1.575019,0,0,0,0,1,120,255,1), -- Induction Samophlange
(@OGUID+4,207263,765,1,361,0,14.71881,-4.829525,-24.02259,2.530723,0,0,0.9537163,0.3007079,120,255,1), -- Skyshredder Crate
(@OGUID+5,207277,0,1,361,0,-4847.016,-6587.738,9.416761,1.204277,0,0,0.5664063,0.8241262,120,255,1), -- Flintlocke's Cannon
(@OGUID+6,207426,0,1,361,0,-4879.241,-6626.441,1.607494,0.7155849,0,0,0.3502073,0.9366722,120,255,1), -- Highbank Prison Gate
(@OGUID+7,207426,0,1,361,0,-4889.691,-6626.29,1.607494,2.234018,0,0,0.8987932,0.4383728,120,255,1), -- Highbank Prison Gate
(@OGUID+8,208209,0,1,0,551,-4838.707,-6615.667,9.265735,4.642579,0,0,-0.7313528,0.6819993,120,255,1), -- Anvil
(@OGUID+9,208827,0,1,361,0,-4847.297,-6588.488,15.46583,1.204277,0,0,0.5664063,0.8241262,120,255,1), -- Cannon Collision
(@OGUID+10,207858,0,1,169,0,-4901.534,-6600.355,20.17789,1.221729,0,0,0.573576,0.8191524,120,255,1), -- Brazier
(@OGUID+11,207859,0,1,169,0,-4914.257,-6611,20.17789,0.2443456,0,0,0.1218691,0.9925462,120,255,1), -- Brazier
(@OGUID+12,190192,0,1,169,0,-4903.218,-6629.801,10.95026,5.410522,0,0,-0.4226179,0.9063079,120,255,1), -- Gate
(@OGUID+13,204949,0,1,169,0,-4858.17,-6607.229,9.35785,0.6981314,0,0,0.34202,0.9396927,120,255,1), -- Anvil
(@OGUID+14,204950,0,1,169,0,-4862,-6602,9.31212,0.6981314,0,0,0.34202,0.9396927,120,255,1), -- Forge
(@OGUID+15,204951,0,1,169,0,-4852.05,-6572.899,9.41676,1.40499,0,0,0.6461239,0.7632326,120,255,1), -- Campfire
(@OGUID+16,205250,0,1,169,0,-4957.64,-6434.22,-14.0343,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+17,205250,0,1,169,0,-4903.25,-6502.08,-60.4497,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+18,205250,0,1,169,0,-5124.15,-6470.2,-57.282,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+19,205250,0,1,169,0,-5118.12,-6447.07,-52.1402,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+20,205250,0,1,169,0,-5106.35,-6484.35,-51.5087,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+21,205250,0,1,169,0,-5123.83,-6477.06,-56.7784,4.101525,0,0,-0.8870106,0.4617491,120,255,1), -- Water-Logged Crate
(@OGUID+22,205250,0,1,169,0,-5064.13,-6410.81,-27.4191,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+23,205250,0,1,169,0,-5039.85,-6407.33,-24.8526,3.089183,0,0,0.9996567,0.02620165,120,255,1), -- Water-Logged Crate
(@OGUID+24,205250,0,1,169,0,-5047.1,-6419.18,-26.551,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+25,205250,0,1,169,0,-5021.06,-6400.41,-24.8993,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+26,205250,0,1,169,0,-5030.69,-6406.58,-25.3359,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+27,205250,0,1,169,0,-5061.62,-6441.08,-30.0793,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+28,205250,0,1,169,0,-5037.19,-6436.4,-28.8455,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+29,205250,0,1,169,0,-4990.42,-6417.05,-17.6729,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+30,205250,0,1,169,0,-4944.61,-6440.7,-16.4767,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+31,205250,0,1,169,0,-4956.05,-6416.44,-9.92276,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+32,205250,0,1,169,0,-5139.96,-6468.84,-62.1752,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+33,205250,0,1,169,0,-5137.81,-6476.38,-62.5336,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+34,205250,0,1,169,0,-5148.78,-6466.51,-62.9869,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+35,205250,0,1,169,0,-5113.49,-6414.91,-39.1962,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+36,205250,0,1,169,0,-5134.13,-6431.98,-59.7174,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+37,205250,0,1,169,0,-5120.78,-6440.43,-53.6066,4.293513,0,0,-0.8386698,0.5446402,120,255,1), -- Water-Logged Crate
(@OGUID+38,205250,0,1,169,0,-5138.01,-6462.57,-62.0067,2.059488,0,0,0.8571672,0.5150382,120,255,1), -- Water-Logged Crate
(@OGUID+39,205250,0,1,169,0,-5158.01,-6452.64,-63.1827,2.82743,0,0,0.9876881,0.1564362,120,255,1), -- Water-Logged Crate
(@OGUID+40,205250,0,1,169,0,-5079.44,-6384.35,-29.4061,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+41,205250,0,1,169,0,-5091.57,-6367.32,-28.2746,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+42,205250,0,1,169,0,-5061.83,-6515.43,-49.4499,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+43,205250,0,1,169,0,-5137.98,-6340.9,-60.5385,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+44,205250,0,1,169,0,-5016.97,-6387.47,-22.4936,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+45,205250,0,1,169,0,-5132.31,-6302.81,-56.5676,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+46,205250,0,1,169,0,-5130.63,-6322.77,-55.9328,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+47,205250,0,1,169,0,-5149.03,-6315.46,-58.5324,3.106652,0,0,0.9998474,0.01746928,120,255,1), -- Water-Logged Crate
(@OGUID+48,205250,0,1,169,0,-5027.97,-6376.82,-20.4385,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+49,205250,0,1,169,0,-5183.04,-6291.31,-59.2101,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+50,205250,0,1,169,0,-5146.34,-6270.36,-55.9578,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+51,205250,0,1,169,0,-5099.99,-6281.65,-22.1667,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+52,205250,0,1,169,0,-5034.32,-6324.43,-18.1762,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+53,205250,0,1,169,0,-4975.37,-6523.98,-70.6844,2.670348,0,0,0.9723692,0.2334484,120,255,1), -- Water-Logged Crate
(@OGUID+54,205250,0,1,169,0,-4983.74,-6520,-70.4004,3.909541,0,0,-0.9271832,0.3746083,120,255,1), -- Water-Logged Crate
(@OGUID+55,205250,0,1,169,0,-5013.55,-6522.33,-63.8293,3.665196,0,0,-0.9659252,0.2588213,120,255,1), -- Water-Logged Crate
(@OGUID+56,205250,0,1,169,0,-5124.6,-6329.88,-52.2005,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+57,205250,0,1,169,0,-5001.16,-6367.45,-17.168,3.194002,0,0,-0.9996567,0.02620165,120,255,1), -- Water-Logged Crate
(@OGUID+58,205250,0,1,169,0,-5018.45,-6510.69,-58.4795,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+59,205250,0,1,169,0,-4946.39,-6356.28,-7.26569,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+60,205250,0,1,169,0,-4978.17,-6386.37,-16.786,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+61,205250,0,1,169,0,-4940.22,-6391.17,-11.3961,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+62,205250,0,1,169,0,-4914.9,-6389.36,-8.54178,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+63,205250,0,1,169,0,-4877.36,-6408.63,-22.1681,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+64,205250,0,1,169,0,-4893.78,-6404.66,-16.4162,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+65,205250,0,1,169,0,-4935.49,-6431.04,-11.5811,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+66,205250,0,1,169,0,-4857.74,-6432.13,-26.7545,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+67,205250,0,1,169,0,-5026.42,-6540.1,-64.3583,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+68,205250,0,1,169,0,-4974.83,-6447.69,-14.728,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+69,205250,0,1,169,0,-4982.93,-6456.06,-16.0921,3.525572,0,0,-0.9816265,0.1908124,120,255,1), -- Water-Logged Crate
(@OGUID+70,205250,0,1,169,0,-4931.95,-6439.38,-15.2949,3.525572,0,0,-0.9816265,0.1908124,120,255,1); -- Water-Logged Crate
