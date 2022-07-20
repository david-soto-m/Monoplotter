project('Monoplotter', 'cpp',
    version: '0.0.1',
    license: 'Unlicense',
)

sources = []

subdir('Axis')
subdir('FilePrinter')
subdir('Function')
subdir('Parser')

sources += ['main.cpp']

executable(
    'monoplotter',
    sources,
)
