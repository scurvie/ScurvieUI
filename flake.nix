{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    utils.url = github:numtide/flake-utils;
  };
  outputs = { self, nixpkgs, utils }:
    utils.lib.eachDefaultSystem (system: let
      pkgs = import nixpkgs { inherit system; };
      ScurvieUI = pkgs.callPackage ./package.nix {};
    in {
      packages.ScurvieUI = ScurvieUI;
      packages.default = ScurvieUI;

      devShells.default = pkgs.mkShell {
        packages = let
          inherit (ScurvieUI) buildInputs nativeBuildInputs;
        in buildInputs ++ nativeBuildInputs ++ [
          pkgs.clang-tools_16
        ];
      };
    });
}
