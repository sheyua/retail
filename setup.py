from typing import List


class Include(object):
    """

    """
    @property
    def cpp_module(self) -> List[str]:
        """

        """
        return [
            'tick.agg.PyBoehmer',
        ]

    def cpp_content(self, name: str, f_type: str) -> List[str]:
        """

        """
        assert name in self.cpp_module

        if f_type == 'cpp':
            if name == 'tick.agg.PyBoehmer':
                return [
                    'tick/agg/PyBoehmer.pyx',
                    '{root_location}/estee/tick/trade/trade.cpp',
                    '{root_location}/estee/tick/inside/inside.cpp',
                    'tick/agg/boehmer.cpp',
                ]
            else:
                raise NotImplementedError
        elif f_type == 'hpp':
            return list()
        else:
            raise NotImplementedError

    @property
    def cython_module(self) -> List[str]:
        """

        """
        return [
            'tick',
            'agg',
        ]


def main():
    """

    """
    from sys import path
    from os import environ
    from os.path import dirname
    from distutils.core import setup

    # check in package to build
    root_location = environ['root_location']
    if root_location not in path:
        path.append(root_location)
    location = dirname(__file__)
    if location not in path:
        path.append(location)
    from estee.util.setup import Setup

    class Collector(Include, Setup): pass
    obj = Collector(location=location, build_dir='build', docstrings=False)
    setup(
        name=obj.package_name,
        version=obj.version,
        ext_modules=obj.make(),
        py_modules=obj.python_package(),
        cmdclass=obj.command_class,
    )


if __name__ == '__main__':
    main()
