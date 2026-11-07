/*
* This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _Gilneas_h__
#define _Gilneas_h__

#include "Position.h"
#include <array>
#include <vector>

namespace Scripts::EasternKingdoms::Gilneas
{
// The knock summons land on the door's trigger 35374 inside the house, and there is no
// navmesh route out through the door frame. The citizen leaves on a fixed spline out of the
// house (the same for every summon at the same door) ending on the door's First marker 35830;
// the Rampaging Worgen leaves the same way.
struct EvacuationDoor
{
    Position Trigger;
    std::vector<Position> Exit;
    bool HasNearMarker; // the citizen runs on to a Near marker 35010 before the Far marker 35011
};

inline std::array<EvacuationDoor, 14> const EvacuationDoors =
{{
    { { -1573.93f, 1381.87f, 36.99f }, { { -1571.10f, 1383.26f, 36.99f }, { -1570.84f, 1384.08f, 37.00f }, { -1570.27f, 1384.89f, 37.00f }, { -1569.99f, 1386.06f, 36.36f }, { -1569.60f, 1387.68f, 36.41f } }, true },
    { { -1566.31f, 1413.51f, 36.64f }, { { -1565.56f, 1413.15f, 36.64f }, { -1564.25f, 1410.68f, 36.64f }, { -1562.61f, 1410.14f, 36.64f }, { -1561.41f, 1410.00f, 36.05f }, { -1561.02f, 1409.96f, 36.03f }, { -1559.24f, 1409.76f, 35.97f } }, true },
    { { -1533.91f, 1447.53f, 36.64f }, { { -1534.16f, 1447.38f, 36.64f }, { -1536.50f, 1445.92f, 36.64f }, { -1537.03f, 1444.28f, 36.64f }, { -1537.21f, 1443.08f, 36.00f }, { -1537.43f, 1441.55f, 35.98f }, { -1537.60f, 1440.43f, 35.97f } }, false },
    { { -1516.33f, 1375.24f, 36.53f }, { { -1516.12f, 1374.76f, 36.53f }, { -1515.00f, 1372.10f, 36.53f }, { -1513.36f, 1371.57f, 36.53f }, { -1512.19f, 1371.46f, 35.99f }, { -1511.78f, 1371.42f, 36.00f }, { -1508.22f, 1371.37f, 36.00f }, { -1506.77f, 1371.35f, 35.56f } }, false },
    { { -1490.54f, 1367.53f, 36.53f }, { { -1491.98f, 1369.91f, 36.53f }, { -1492.25f, 1370.35f, 36.53f } }, true },
    { { -1459.78f, 1447.69f, 36.64f }, { { -1460.54f, 1447.27f, 36.64f }, { -1462.97f, 1445.92f, 36.64f }, { -1463.50f, 1444.28f, 36.64f }, { -1463.67f, 1443.09f, 36.00f }, { -1463.85f, 1441.79f, 35.98f }, { -1463.95f, 1441.07f, 35.98f } }, true },
    { { -1425.08f, 1409.70f, 36.78f }, { { -1422.31f, 1411.31f, 36.79f }, { -1421.92f, 1412.21f, 36.79f }, { -1421.58f, 1412.98f, 36.79f }, { -1421.45f, 1414.15f, 36.00f }, { -1421.33f, 1415.59f, 36.00f }, { -1421.35f, 1416.15f, 35.56f }, { -1421.13f, 1417.47f, 35.56f } }, true },
    { { -1423.91f, 1432.49f, 36.41f }, { { -1424.02f, 1432.78f, 36.41f }, { -1425.08f, 1435.50f, 36.41f }, { -1426.72f, 1435.39f, 36.42f }, { -1427.91f, 1435.30f, 35.80f }, { -1428.31f, 1435.28f, 35.76f }, { -1428.84f, 1435.50f, 35.77f }, { -1431.40f, 1436.61f, 35.91f }, { -1432.41f, 1437.04f, 35.85f } }, true },
    { { -1391.25f, 1399.27f, 36.41f }, { { -1392.84f, 1402.06f, 36.41f }, { -1393.74f, 1402.46f, 36.42f }, { -1394.52f, 1402.79f, 36.42f }, { -1395.29f, 1402.92f, 36.11f }, { -1395.95f, 1403.03f, 35.92f }, { -1396.41f, 1403.11f, 35.95f }, { -1397.94f, 1403.38f, 35.95f } }, true },
    { { -1489.31f, 1330.34f, 36.48f }, { { -1486.98f, 1332.52f, 36.48f }, { -1487.00f, 1333.06f, 36.48f }, { -1486.73f, 1334.34f, 36.48f }, { -1487.24f, 1335.41f, 35.85f }, { -1487.60f, 1336.16f, 35.84f }, { -1487.98f, 1336.95f, 35.84f }, { -1488.02f, 1336.98f, 35.56f }, { -1487.75f, 1337.39f, 35.56f } }, true },
    { { -1531.89f, 1318.65f, 36.57f }, { { -1530.18f, 1320.76f, 36.58f }, { -1530.22f, 1321.30f, 36.57f }, { -1529.93f, 1322.56f, 36.57f }, { -1530.11f, 1323.75f, 35.85f }, { -1530.23f, 1324.56f, 35.85f }, { -1530.51f, 1325.68f, 35.84f } }, false },
    { { -1579.76f, 1339.98f, 36.53f }, { { -1577.44f, 1336.96f, 36.53f }, { -1576.58f, 1336.39f, 36.53f }, { -1575.37f, 1336.25f, 35.90f }, { -1573.89f, 1336.07f, 35.85f }, { -1572.84f, 1336.02f, 35.82f } }, false },
    { { -1587.82f, 1356.02f, 36.52f }, { { -1584.67f, 1357.42f, 36.53f }, { -1584.31f, 1359.09f, 36.53f }, { -1584.05f, 1360.28f, 35.99f }, { -1583.91f, 1360.68f, 36.00f }, { -1583.68f, 1361.84f, 36.00f }, { -1583.99f, 1362.33f, 36.00f }, { -1584.24f, 1362.71f, 35.94f } }, false },
    // Blizzlike: behind this door is a second door that cannot be opened, so there is no path out.
    // The citizen says its line where it appears, gives the credit and despawns.
    { { -1545.37f, 1306.57f, 36.50f }, { }, false }
}};
}

#endif // _Gilneas_h__
