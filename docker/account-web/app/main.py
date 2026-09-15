"""account-web - a single-form UI for creating WoW accounts against this
stack's own worldserver, over its SOAP console interface (TC_SOAP_URL,
enabled in deploy/worldserver.conf) rather than writing to the `auth`
database directly. AccountMgr::CreateAccount() normalizes the username,
enforces MAX_ACCOUNT_STR (16), and generates the SRP6 salt/verifier -
logic this app has no business reimplementing, so TrinityCore itself stays
the only thing that ever writes an account row. See README_DEV.md
"Account creation web UI" for the one-time SOAP admin account bootstrap
this depends on.
"""
from __future__ import annotations

import os
from pathlib import Path

from fastapi import Depends, FastAPI, Form, Request
from fastapi.responses import HTMLResponse
from fastapi.templating import Jinja2Templates

from .soap_client import SoapCommandError, SoapConfig, SoapUnavailable, execute_command

app = FastAPI(title="account-web", version="0.1.0")
templates = Jinja2Templates(directory=str(Path(__file__).parent / "templates"))

MAX_ACCOUNT_STR = 16  # src/server/game/Accounts/AccountMgr.h - username and password both


def get_soap_config() -> SoapConfig:
    return SoapConfig(
        url=os.environ["TC_SOAP_URL"],
        username=os.environ["TC_SOAP_USER"],
        password=os.environ["TC_SOAP_PASSWORD"],
    )


@app.get("/health")
def health() -> dict:
    return {"status": "ok"}


@app.get("/", response_class=HTMLResponse)
def form(request: Request) -> HTMLResponse:
    return templates.TemplateResponse(request, "index.html", {})


def _validate(username: str, password: str) -> str | None:
    if not username or not password:
        return "Jméno i heslo jsou povinné."
    if len(username) > MAX_ACCOUNT_STR or len(password) > MAX_ACCOUNT_STR:
        return f"Jméno i heslo musí mít nejvýše {MAX_ACCOUNT_STR} znaků."
    # The console command is space-delimited ("account create NAME PASS"),
    # so a space inside either field would shift its arguments rather than
    # become part of the name/password - reject it outright instead of
    # sending TrinityCore a command it would misparse.
    if any(char.isspace() for char in username) or any(char.isspace() for char in password):
        return "Jméno ani heslo nesmí obsahovat mezery."
    return None


@app.post("/accounts", response_class=HTMLResponse)
def create_account(
    request: Request,
    username: str = Form(...),
    password: str = Form(...),
    admin: bool = Form(False),
    northrend: bool = Form(False),
    config: SoapConfig = Depends(get_soap_config),
) -> HTMLResponse:
    error = _validate(username, password)
    if error:
        return templates.TemplateResponse(request, "index.html", {"error": error})

    try:
        execute_command(config, f"account create {username} {password}")
    except SoapCommandError as exc:
        return templates.TemplateResponse(request, "index.html", {"error": str(exc)})
    except SoapUnavailable as exc:
        return templates.TemplateResponse(request, "index.html", {"error": str(exc)})

    # Account row now exists. Expansion and (optionally) gmlevel follow;
    # either failing leaves a half-configured account nobody asked for, so
    # roll the whole thing back rather than leave it half-done.
    expansion = 2 if northrend else 1
    try:
        execute_command(config, f"account set addon {username} {expansion}")
        if admin:
            execute_command(config, f"account set gmlevel {username} 3 -1")
    except (SoapCommandError, SoapUnavailable) as exc:
        try:
            execute_command(config, f"account delete {username}")
        except (SoapCommandError, SoapUnavailable):
            pass  # best-effort cleanup; the error below still surfaces
        return templates.TemplateResponse(
            request,
            "index.html",
            {"error": f"Účet se nepodařilo nakonfigurovat, byl zrušen: {exc}"},
        )

    return templates.TemplateResponse(
        request,
        "index.html",
        {
            "success": {
                "username": username,
                "admin": admin,
                "northrend": northrend,
            }
        },
    )
