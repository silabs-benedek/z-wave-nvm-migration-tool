#!/usr/bin/env bash
# Prompts for debug arguments, remembers last value, and writes GDB init file.
# Usage: run from workspace root (e.g. via a VS Code preLaunchTask).
# Creates: .vscode/last_args, .vscode/gdb_init_args

set -e
LAST_ARGS_FILE=".vscode/last_args"
GDB_INIT_FILE=".vscode/gdb_init_args"

default=""
[[ -f "$LAST_ARGS_FILE" ]] && default=$(cat "$LAST_ARGS_FILE")

if command -v zenity &>/dev/null; then
  input=$(zenity --entry --title="Debug arguments" \
    --text="Enter command-line arguments (e.g. -e file.bin -o out.json):" \
    --entry-text="$default" 2>/dev/null) || true
  [[ -z "$input" ]] && input="$default"
else
  if [[ -n "$default" ]]; then
    echo "Last arguments: $default"
    echo "Press Enter to reuse, or type new arguments:"
  else
    echo "Enter command-line arguments (e.g. -e file.bin -o out.json):"
  fi
  # -e enables readline so arrow keys and backspace work (no literal escape sequences)
  read -r -e input
  [[ -z "$input" ]] && input="$default"
fi

echo "$input" > "$LAST_ARGS_FILE"
echo "set args $input" > "$GDB_INIT_FILE"
