# account-web - single-form UI that creates WoW accounts via worldserver's
# SOAP console interface. See README_DEV.md "Account creation web UI".
FROM python:3.11-slim

WORKDIR /app

RUN pip install --no-cache-dir fastapi uvicorn httpx jinja2 python-multipart

COPY app/ ./app/
COPY tests/ ./tests/

EXPOSE 8000

CMD ["uvicorn", "app.main:app", "--host", "0.0.0.0", "--port", "8000"]
