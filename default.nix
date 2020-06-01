with import <nixpkgs> {};

stdenv.mkDerivation {

  name = "libprime-0.1";

  src = builtins.path {path = ./.;};

  buildPhase = ''
    gcc -fPIC -c sources/prime.c
    gcc -shared -o libprime.so prime.o headers/prime.h
  '';

  installPhase = ''
    mkdir -p $out/lib
    mkdir -p $out/include

    cp libprime.so $out/lib
    cp headers/prime.h $out/include
  '';
}
