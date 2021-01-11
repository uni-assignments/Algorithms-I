EXEC=$1
TMP_OUT=$2

for i in {1..9..1}; do
  testname=$(printf "%01d" $i)
  $EXEC < casos_teste/$testname.in > $TMP_OUT
  if ! diff -qwB casos_teste/$testname.out $TMP_OUT &>/dev/null; then
    diff -wBy casos_teste/$testname.out $TMP_OUT > output/$testname.log
    echo "Test $testname failed"
  else
    echo "Test $testname passed"
  fi
done
rm $TMP_OUT