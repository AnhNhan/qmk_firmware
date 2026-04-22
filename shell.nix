{
  pkgs ? import <nixpkgs> { },
}:
pkgs.mkShell {
  # nativeBuildInputs is usually what you want -- tools you need to run
  nativeBuildInputs = with pkgs.buildPackages; [ ];

  buildInputs = [ ];

  packages = with pkgs; [
    qmk
    qmk-udev-rules
  ];
}
