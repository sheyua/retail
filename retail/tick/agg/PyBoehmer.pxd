from estee.tick.core.PyHandler cimport Handler, PyHandler


cdef extern from './boehmer.hpp' namespace 'tick':
    cdef cppclass Boehmer(Handler) nogil:
        # constructor
        Boehmer(double) except +


cdef class PyBoehmer(PyHandler):
    """

    """
    pass
