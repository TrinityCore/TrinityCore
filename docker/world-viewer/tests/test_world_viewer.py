"""Receiver tests use FastAPI TestClient; no worldserver or network is needed."""
from __future__ import annotations

import unittest
from unittest.mock import patch

from fastapi.testclient import TestClient

from app.main import create_app
from app.telemetry import MAX_AGENTS, MAX_REQUEST_BYTES


def agent(agent_id: int = 80542, source: str = "live") -> dict:
    return {
        "agent_id": agent_id,
        "spawn_id": agent_id,
        "entry": 252,
        "name": "Billy Maclure",
        "type": "CIVILIAN",
        "control_mode": "AI_WORLD_CONTROLLED",
        "world_faction": 1,
        "world_state": "MATERIALIZED" if source == "live" else "ABSTRACT",
        "simulation_tier": "NEARBY",
        "position": {"x": -9923.68, "y": 38.39, "z": 32.6, "map_id": 0, "source": source},
        "health": 84,
        "max_health": 100,
        "alive": True,
        "in_combat": False,
        "needs": {
            "health_pressure": 0.16,
            "hunger": 0.71,
            "fatigue": 0.32,
            "safety_pressure": 0.0,
            "resource_pressure": 0.18,
        },
        "goal": "GET_FOOD",
        "goal_utility": 0.71,
        "action": "MOVE_TO",
        "routine_goal": "GO_HOME",
        "group_id": 17,
    }


def batch(agents: list[dict] | None = None) -> dict:
    return {"version": 1, "captured_at_ms": 1_800_000_000_000, "agents": agents if agents is not None else [agent()]}


class WorldViewerApiTests(unittest.TestCase):
    def setUp(self) -> None:
        self.client = TestClient(create_app("test-secret"))
        self.headers = {"Authorization": "Bearer test-secret"}

    def tearDown(self) -> None:
        self.client.close()

    def test_public_state_starts_empty_and_stale(self) -> None:
        state = self.client.get("/api/state").json()
        self.assertTrue(state["configured"])
        self.assertTrue(state["stale"])
        self.assertIsNone(state["captured_at_ms"])
        self.assertEqual(state["agents"], [])

    def test_post_requires_correct_bearer_token(self) -> None:
        for headers in ({}, {"Authorization": "Basic test-secret"}, {"Authorization": "Bearer wrong"}):
            with self.subTest(headers=headers):
                self.assertEqual(self.client.post("/internal/telemetry", headers=headers, json=batch()).status_code, 401)
        self.assertEqual(self.client.get("/api/state").json()["agents"], [])

    def test_unconfigured_service_rejects_ingest(self) -> None:
        with TestClient(create_app("")) as client:
            self.assertFalse(client.get("/health").json()["telemetry_configured"])
            self.assertEqual(client.post("/internal/telemetry", headers=self.headers, json=batch()).status_code, 503)

    def test_accepts_snapshot_and_replaces_previous_batch(self) -> None:
        response = self.client.post("/internal/telemetry", headers=self.headers, json=batch([agent(), agent(80543, "spawn")]))
        self.assertEqual(response.status_code, 200)
        self.assertEqual(response.json(), {"accepted": 2})
        state = self.client.get("/api/state").json()
        self.assertEqual(state["captured_at_ms"], 1_800_000_000_000)
        self.assertFalse(state["stale"])
        self.assertEqual([item["agent_id"] for item in state["agents"]], [80542, 80543])
        self.assertEqual(state["agents"][1]["position"]["source"], "spawn")
        self.assertEqual(self.client.post("/internal/telemetry", headers=self.headers, json=batch([agent(9)])).json(), {"accepted": 1})
        self.assertEqual([item["agent_id"] for item in self.client.get("/api/state").json()["agents"]], [9])

    def test_stale_uses_receive_clock_not_source_timestamp(self) -> None:
        self.client.post("/internal/telemetry", headers=self.headers, json=batch())
        app = self.client.app
        with patch("app.main.time.monotonic", return_value=app.state.received_monotonic + 5.1):
            state = self.client.get("/api/state").json()
        self.assertTrue(state["stale"])
        self.assertGreaterEqual(state["age_ms"], 5000)

    def test_rejects_invalid_or_duplicate_batches_without_replacing_cache(self) -> None:
        self.client.post("/internal/telemetry", headers=self.headers, json=batch())
        invalid = [
            {**batch(), "version": 2},
            batch([{**agent(), "position": {**agent()["position"], "source": "unknown"}}]),
            batch([{**agent(), "needs": {**agent()["needs"], "hunger": 1.5}}]),
            batch([agent(1), agent(1)]),
        ]
        for payload in invalid:
            with self.subTest(payload=payload.get("version")):
                self.assertEqual(self.client.post("/internal/telemetry", headers=self.headers, json=payload).status_code, 422)
        self.assertEqual(self.client.get("/api/state").json()["agents"][0]["agent_id"], 80542)

    def test_rejects_malformed_json_without_replacing_cache(self) -> None:
        self.client.post("/internal/telemetry", headers=self.headers, json=batch())
        response = self.client.post("/internal/telemetry", headers=self.headers, content=b"{broken")
        self.assertEqual(response.status_code, 400)
        self.assertEqual(self.client.get("/api/state").json()["agents"][0]["agent_id"], 80542)

    def test_payload_byte_cap_and_agent_cap(self) -> None:
        oversized = b"{" + b" " * MAX_REQUEST_BYTES + b"}"
        response = self.client.post("/internal/telemetry", headers=self.headers, content=oversized)
        self.assertEqual(response.status_code, 413)
        too_many = batch([agent(i) for i in range(MAX_AGENTS + 1)])
        self.assertEqual(self.client.post("/internal/telemetry", headers=self.headers, json=too_many).status_code, 422)

    def test_page_is_read_only_and_served_without_token(self) -> None:
        response = self.client.get("/")
        self.assertEqual(response.status_code, 200)
        self.assertIn("Elwynn Forest", response.text)
        self.assertEqual(self.client.post("/api/state").status_code, 405)


if __name__ == "__main__":
    unittest.main()
