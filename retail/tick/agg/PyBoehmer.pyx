cdef class PyBoehmer:
    """

    """
    # constructor & overload
    def __cinit__(self, double tick_size) -> None:
        """

        """
        self.pointer = new Boehmer(tick_size)

    def __init__(self, double tick_size) -> None: pass

    def __dealloc__(self) -> None: del self.pointer
