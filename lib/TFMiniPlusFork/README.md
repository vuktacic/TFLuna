TFMiniPlus (local fork)
=======================

This directory contains a local fork of the TFMiniPlus Arduino library with
one defensive fix to prevent buffer overruns when parsing command responses.

Why a local fork?
- The project previously relied on the PlatformIO-managed package
  senegalo/TFMiniPlus. To ship a fix quickly and ensure deterministic builds
  we keep a local fork inside lib/TFMiniPlusFork and use it as a PlatformIO
  local library.

What changed
- Added validation of the length byte in readCommandResponse to avoid reading
  more bytes than the local command-response buffer can hold. On invalid
  length the function drains a small amount of data to resynchronize and
  returns false instead of causing undefined behaviour.

How to publish this fork to GitHub
1. Create a new repository on GitHub (empty) where you want to host the fork.
2. From the repo root run the following commands to push this local library only:

   git add lib/TFMiniPlusFork
   git commit -m "Add local fork of TFMiniPlus with defensive read fix"
   # Create a branch for the library changes if you prefer
   git push origin HEAD:refs/heads/tfminiplus-fork

3. Alternatively, if you only want the library files in a dedicated repo,
   create a new local repo under the library folder and push it:

   cd lib/TFMiniPlusFork
   git init
   git add .
   git commit -m "Initial fork of TFMiniPlus with readCommandResponse fix"
   git remote add origin <YOUR_NEW_REPO_URL>
   git push -u origin main

Using the GitHub fork as a dependency
- Option A (PlatformIO lib_deps): If you push the fork to GitHub as e.g.
  username/TFMiniPlus, you can depend on it in platformio.ini using
  `username/TFMiniPlus` in lib_deps and remove the local copy (or keep local
  and rely on the remote instead).
- Option B (git URL): You can also reference the specific Git URL in
  lib_deps: `git+https://github.com/username/TFMiniPlus.git#branch`

Notes
- I did not create any git commits or push to remote — you must run the
  chosen git commands locally to publish.
