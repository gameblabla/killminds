Name: harbour-killminds
Summary: The ultimate Puzzle game !
Version: 1.1
Release: 2
Group: Applications
License: LICENSE
URL: https://gameblabla.nl
Source0: %{name}-%{version}.tar.bz2
BuildRequires: pkgconfig(sdl2)
BuildRequires: pkgconfig(egl)
BuildRequires: pkgconfig(glesv1_cm)
BuildRequires: pkgconfig(glesv2)
#BuildRequires: pkgconfig(openal)

%description
The ultimate Puzzle game that will blow your mind !

%prep
%setup -q -n %{name}-%{version}
# Command used to configure / set up the application
#%configure

%build
# Command used to compile the application
make -f Makefile.sail

%install
rm -rf %{buildroot}
# Command used to install files into %{buildroot}
make -f Makefile.sail install

%files
%defattr(-,root,root,-)
%{_bindir}/%{name}
%{_datadir}/applications/%{name}.desktop
%{_datadir}/icons/hicolor/86x86/apps/%{name}.png
%{_datadir}/%{name}/all.bmp
%{_datadir}/%{name}/back.bmp
%{_datadir}/%{name}/background.bmp
%{_datadir}/%{name}/block.bmp
%{_datadir}/%{name}/smallblock.bmp
%{_datadir}/%{name}/copyright.bmp
%{_datadir}/%{name}/hand_anim.bmp
%{_datadir}/%{name}/heart.bmp
%{_datadir}/%{name}/inst.bmp
%{_datadir}/%{name}/score.bmp
%{_datadir}/%{name}/startbutton.bmp
%{_datadir}/%{name}/title.bmp
%{_datadir}/%{name}/trophees.bmp
%{_datadir}/%{name}/downleft.wav
%{_datadir}/%{name}/downright.wav
%{_datadir}/%{name}/fullsquare.wav
%{_datadir}/%{name}/gameover.wav
%{_datadir}/%{name}/miss.wav
%{_datadir}/%{name}/move1.wav
%{_datadir}/%{name}/move2.wav
%{_datadir}/%{name}/move3.wav
%{_datadir}/%{name}/move4.wav
%{_datadir}/%{name}/upleft.wav
%{_datadir}/%{name}/upright.wav
