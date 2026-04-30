#!/usr/bin/env bash
# Helper script to publish the local fork directory to a new GitHub repo
# Usage: ./publish_fork.sh <git-remote-url> [branch]

set -euo pipefail

if [ "$#" -lt 1 ]; then
  echo "Usage: $0 <git-remote-url> [branch]"
  exit 2
fi

REMOTE_URL="$1"
BRANCH="${2:-main}"

cd "$(dirname "$0")"

if [ -d .git ]; then
  echo "Directory already a git repo; will push to $REMOTE_URL ($BRANCH)"
else
  git init
  git add .
  git commit -m "Initial fork of TFMiniPlus with defensive readCommandResponse fix"
fi

git remote add origin "$REMOTE_URL" 2>/dev/null || git remote set-url origin "$REMOTE_URL"
git branch -M "$BRANCH"
git push -u origin "$BRANCH"

echo "Pushed local fork to $REMOTE_URL on branch $BRANCH"
